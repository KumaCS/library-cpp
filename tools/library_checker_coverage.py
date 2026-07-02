#!/usr/bin/env python3
import argparse
import csv
import json
import re
import sys
import tomllib
import urllib.request
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCAN_ROOT = ROOT
CACHE_PATH = ROOT / "cache" / "library_checker_problems.json"
TREE_URL = "https://api.github.com/repos/yosupo06/library-checker-problems/git/trees/master?recursive=1"
CATEGORIES_URL = "https://raw.githubusercontent.com/yosupo06/library-checker-problems/master/categories.toml"
PROBLEM_URL = "https://judge.yosupo.jp/problem/"

PROBLEM_RE = re.compile(r'#\s*define\s+PROBLEM\s+"([^"]+)"')
INCLUDE_RE = re.compile(r'#\s*include\s+"([^"]+\.hpp)"')


def fetch_bytes(url: str) -> bytes:
    request = urllib.request.Request(url, headers={"User-Agent": "library-checker-coverage"})
    with urllib.request.urlopen(request, timeout=30) as response:
        return response.read()


def problem_id_from_url(url: str) -> str | None:
    if not url.startswith(PROBLEM_URL):
        return None
    return url.removeprefix(PROBLEM_URL).split("/", 1)[0].split("?", 1)[0]


def title_from_id(problem_id: str) -> str:
    words = []
    for word in problem_id.split("_"):
        if word in {"f", "mod", "gcd", "lcm", "mst", "scc", "rmq", "lca"}:
            words.append(word.upper())
        elif word in {"2", "64", "128bit", "1000000007"}:
            words.append(word)
        else:
            words.append(word.capitalize())
    return " ".join(words)


def parse_categories(categories_toml: bytes) -> dict[str, str]:
    data = tomllib.loads(categories_toml.decode())
    result = {}
    for category in data.get("categories", []):
        name = category.get("name", "")
        for problem_id in category.get("problems", []):
            result[problem_id] = name
    return result


def load_remote_problems(refresh: bool) -> list[dict[str, str]]:
    if CACHE_PATH.exists() and not refresh:
        return json.loads(CACHE_PATH.read_text())

    tree_data = json.loads(fetch_bytes(TREE_URL))
    category_names = parse_categories(fetch_bytes(CATEGORIES_URL))

    problems = {}
    for entry in tree_data.get("tree", []):
        path = entry.get("path", "")
        if not path.endswith("/info.toml"):
            continue
        directory, _, _ = path.rpartition("/")
        category_dir, _, problem_id = directory.partition("/")
        if not problem_id:
            continue
        problems[problem_id] = {
            "id": problem_id,
            "title": title_from_id(problem_id),
            "category": category_names.get(problem_id, category_dir.replace("_", " ").title()),
            "path": directory,
            "url": f"{PROBLEM_URL}{problem_id}",
        }

    ordered_ids = list(category_names)
    ordered_ids += sorted(problem_id for problem_id in problems if problem_id not in category_names)
    result = [problems[problem_id] for problem_id in ordered_ids if problem_id in problems]

    CACHE_PATH.parent.mkdir(parents=True, exist_ok=True)
    CACHE_PATH.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n")
    return result


def scan_local_verifications(include_unit: bool) -> dict[str, dict[str, list[str]]]:
    verified = defaultdict(lambda: {"tests": [], "headers": []})
    for path in sorted((SCAN_ROOT / "verify").glob("**/*.test.cpp")):
        if not include_unit and not path.name.startswith("LC_"):
            continue
        text = path.read_text(errors="replace")
        problem_match = PROBLEM_RE.search(text)
        if not problem_match:
            continue
        problem_id = problem_id_from_url(problem_match.group(1))
        if problem_id is None:
            continue

        rel_test = path.relative_to(SCAN_ROOT).as_posix()
        verified[problem_id]["tests"].append(rel_test)

        for header in INCLUDE_RE.findall(text):
            if header.startswith("template/"):
                continue
            if header not in verified[problem_id]["headers"]:
                verified[problem_id]["headers"].append(header)

    return dict(verified)


def build_rows(problems: list[dict[str, str]], verified: dict[str, dict[str, list[str]]]) -> list[dict[str, object]]:
    rows = []
    for problem in problems:
        local = verified.get(problem["id"], {"tests": [], "headers": []})
        rows.append(
            {
                **problem,
                "covered": bool(local["tests"]),
                "tests": local["tests"],
                "headers": local["headers"],
            }
        )
    return rows


def filter_rows(rows: list[dict[str, object]], mode: str) -> list[dict[str, object]]:
    if mode == "covered":
        return [row for row in rows if row["covered"]]
    if mode == "missing":
        return [row for row in rows if not row["covered"]]
    return rows


def coverage_stats(rows: list[dict[str, object]]) -> dict[str, int]:
    total = len(rows)
    covered = sum(1 for row in rows if row["covered"])
    return {"covered": covered, "total": total, "missing": total - covered}


def category_stats(rows: list[dict[str, object]]) -> dict[str, dict[str, int]]:
    result = defaultdict(lambda: {"covered": 0, "total": 0})
    for row in rows:
        result[row["category"]]["total"] += 1
        result[row["category"]]["covered"] += bool(row["covered"])
    return dict(result)


def print_summary(rows: list[dict[str, object]]) -> None:
    stats = coverage_stats(rows)
    total = stats["total"]
    covered = stats["covered"]
    missing = stats["missing"]
    rate = 0.0 if total == 0 else covered * 100.0 / total
    print(f"Library Checker coverage: {covered}/{total} ({rate:.1f}%), missing {missing}")

    print()
    print("| Category | Covered | Total | Rate |")
    print("|---|---:|---:|---:|")
    for category, stats in sorted(category_stats(rows).items()):
        category_covered = stats["covered"]
        category_total = stats["total"]
        category_rate = 0.0 if category_total == 0 else category_covered * 100.0 / category_total
        print(f"| {category} | {category_covered} | {category_total} | {category_rate:.1f}% |")


def compare_rows(previous_rows: list[dict[str, object]], current_rows: list[dict[str, object]]) -> dict[str, object]:
    previous_by_id = {row["id"]: row for row in previous_rows}
    current_by_id = {row["id"]: row for row in current_rows}
    previous_covered = {problem_id for problem_id, row in previous_by_id.items() if row["covered"]}
    current_covered = {problem_id for problem_id, row in current_by_id.items() if row["covered"]}

    newly_covered = sorted(current_covered - previous_covered)
    no_longer_covered = sorted(previous_covered - current_covered)

    return {
        "previous": coverage_stats(previous_rows),
        "current": coverage_stats(current_rows),
        "previous_categories": category_stats(previous_rows),
        "current_categories": category_stats(current_rows),
        "newly_covered": [current_by_id[problem_id] for problem_id in newly_covered if problem_id in current_by_id],
        "no_longer_covered": [
            current_by_id.get(problem_id, previous_by_id[problem_id])
            for problem_id in no_longer_covered
            if problem_id in previous_by_id
        ],
    }


def signed(value: int) -> str:
    return f"+{value}" if value > 0 else str(value)


def print_compare(compare: dict[str, object], link_prefix: str) -> None:
    previous = compare["previous"]
    current = compare["current"]
    covered_delta = current["covered"] - previous["covered"]
    total_delta = current["total"] - previous["total"]

    print()
    print("## Coverage diff")
    print()
    print(
        f"Covered: {previous['covered']}/{previous['total']} -> "
        f"{current['covered']}/{current['total']} "
        f"({signed(covered_delta)} covered, {signed(total_delta)} total)"
    )

    print()
    print("| Category | Covered | Total |")
    print("|---|---:|---:|")
    previous_categories = compare["previous_categories"]
    current_categories = compare["current_categories"]
    for category in sorted(set(previous_categories) | set(current_categories)):
        previous_category = previous_categories.get(category, {"covered": 0, "total": 0})
        current_category = current_categories.get(category, {"covered": 0, "total": 0})
        category_covered_delta = current_category["covered"] - previous_category["covered"]
        category_total_delta = current_category["total"] - previous_category["total"]
        print(
            f"| {category} | {previous_category['covered']} -> {current_category['covered']} "
            f"({signed(category_covered_delta)}) | {previous_category['total']} -> "
            f"{current_category['total']} ({signed(category_total_delta)}) |"
        )

    if compare["newly_covered"]:
        print()
        print("### Newly covered")
        print()
        print_markdown(compare["newly_covered"], link_prefix)

    if compare["no_longer_covered"]:
        print()
        print("### No longer covered")
        print()
        print_markdown(compare["no_longer_covered"], link_prefix)


def markdown_link(path: str, link_prefix: str) -> str:
    return f"[`{path}`]({link_prefix}{path})"


def rows_by_category(rows: list[dict[str, object]]) -> dict[str, list[dict[str, object]]]:
    grouped = {}
    for row in rows:
        grouped.setdefault(row["category"], []).append(row)
    return grouped


def print_markdown(rows: list[dict[str, object]], link_prefix: str) -> None:
    first = True
    for category, category_rows in rows_by_category(rows).items():
        if first:
            first = False
        else:
            print()
        print(f"### {category} ({len(category_rows)})")
        print()
        print("| Status | Problem | Headers | Tests |")
        print("|---|---|---|---|")
        for row in category_rows:
            status = "✅" if row["covered"] else "❌"
            problem = f"[{row['id']}]({row['url']})"
            headers = "<br>".join(markdown_link(header, link_prefix) for header in row["headers"]) or "-"
            tests = "<br>".join(markdown_link(test, link_prefix) for test in row["tests"]) or "-"
            print(f"| {status} | {problem} | {headers} | {tests} |")


def print_page(rows: list[dict[str, object]], link_prefix: str, title: str) -> None:
    print("---")
    print(f"title: {title}")
    print("layout: page")
    print("---")
    print()
    print(f"# {title}")
    print()
    print_summary(rows)
    print()
    print_markdown(rows, link_prefix)


def update_pages_index(index_path: Path) -> None:
    text = index_path.read_text()
    if "library-checker-coverage" in text:
        return

    marker = "layout: toppage\n"
    if marker not in text:
        raise ValueError(f"cannot find {marker.strip()} in {index_path}")

    block = (
        "  - name: reports\n"
        "    pages:\n"
        "    - icon: ':bar_chart:'\n"
        "      path: library-checker-coverage\n"
        "      title: Library Checker coverage\n"
    )
    index_path.write_text(text.replace(marker, block + marker, 1))


def print_csv(rows: list[dict[str, object]]) -> None:
    writer = csv.DictWriter(sys.stdout, fieldnames=["covered", "category", "id", "title", "url", "headers", "tests"])
    writer.writeheader()
    for row in rows:
        writer.writerow(
            {
                "covered": row["covered"],
                "category": row["category"],
                "id": row["id"],
                "title": row["title"],
                "url": row["url"],
                "headers": " ".join(row["headers"]),
                "tests": " ".join(row["tests"]),
            }
        )


def main() -> int:
    global CACHE_PATH, SCAN_ROOT

    parser = argparse.ArgumentParser(description="List Library Checker problems and local verification coverage.")
    parser.add_argument("--refresh", action="store_true", help="fetch the current problem list and update the cache")
    parser.add_argument("--mode", choices=["all", "covered", "missing"], default="missing", help="rows to print")
    parser.add_argument(
        "--format",
        choices=["summary", "markdown", "json", "csv", "page"],
        default="summary",
        help="output format",
    )
    parser.add_argument("--cache", type=Path, default=CACHE_PATH, help="problem list cache path")
    parser.add_argument("--include-unit", action="store_true", help="also treat UNIT_*.test.cpp files as coverage")
    parser.add_argument("--link-prefix", default="", help="prefix for repository file links in markdown output")
    parser.add_argument("--root", type=Path, default=ROOT, help="repository root to scan")
    parser.add_argument("--compare-json", type=Path, help="previous coverage JSON for diff output")
    parser.add_argument("--fail-on-decrease", action="store_true", help="fail if covered problems decrease")
    parser.add_argument("--update-pages-index", type=Path, help="add the coverage page to a verify-helper index.md")
    args = parser.parse_args()

    CACHE_PATH = args.cache
    SCAN_ROOT = args.root.resolve()

    try:
        problems = load_remote_problems(args.refresh)
    except Exception as exc:
        print(f"failed to load Library Checker problem list: {exc}", file=sys.stderr)
        if not CACHE_PATH.exists():
            print("hint: run with --refresh when network access is available", file=sys.stderr)
        return 1

    rows = build_rows(problems, scan_local_verifications(args.include_unit))
    selected = filter_rows(rows, args.mode)
    compare = None
    if args.compare_json:
        compare = compare_rows(json.loads(args.compare_json.read_text()), rows)

    if args.format == "summary":
        print_summary(rows)
        if compare:
            print_compare(compare, args.link_prefix)
        if args.mode != "all" or selected != rows:
            print()
            print_markdown(selected, args.link_prefix)
    elif args.format == "markdown":
        print_markdown(selected, args.link_prefix)
    elif args.format == "json":
        print(json.dumps(selected, indent=2, ensure_ascii=False))
    elif args.format == "csv":
        print_csv(selected)
    elif args.format == "page":
        print_page(selected, args.link_prefix, "Library Checker coverage")

    if args.update_pages_index:
        update_pages_index(args.update_pages_index)

    if args.fail_on_decrease and compare:
        if compare["current"]["covered"] < compare["previous"]["covered"] or compare["no_longer_covered"]:
            print("Library Checker coverage decreased", file=sys.stderr)
            return 2
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
