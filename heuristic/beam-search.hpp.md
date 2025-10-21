---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: heuristic/time-keeper.hpp
    title: heuristic/time-keeper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/heuristic/beam-search.md
    document_title: Beam Search
    links: []
  bundledCode: "#line 2 \"heuristic/time-keeper.hpp\"\n\nclass TimeKeeper {\n private:\n\
    \  chrono::high_resolution_clock::time_point start_time_;\n  int time_threshold_;\n\
    \n public:\n  TimeKeeper(int time_threshold) : start_time_(chrono::high_resolution_clock::now()),\
    \ time_threshold_(time_threshold) {}\n  bool is_time_over() const {\n    auto\
    \ diff = chrono::high_resolution_clock::now() - this->start_time_;\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(diff).count() >= time_threshold_;\n\
    \  }\n};\n#line 3 \"heuristic/beam-search.hpp\"\n\ntemplate <class State>\nint\
    \ BeamSearch(const State& state, const int beam_width, int time_threshold) {\n\
    \  auto time_keeper = TimeKeeper(time_threshold);\n  priority_queue<State> now_beam;\n\
    \  State best_state;\n  now_beam.push(state);\n  for (int t = 0;; t++) {\n   \
    \ priority_queue<State> next_beam;\n    for (int i = 0; i < beam_width; i++) {\n\
    \      if (time_keeper.is_time_over()) return best_state.root_action;\n      if\
    \ (now_beam.empty()) break;\n      State now_state = now_beam.top();\n      now_beam.pop();\n\
    \      auto actions = now_state.next_actions();\n      for (const auto& action\
    \ : actions) {\n        State next_state = now_state;\n        next_state.advance(action);\n\
    \        next_state.eval_score();\n        if (t == 0) next_state.root_action\
    \ = action;\n        next_beam.push(next_state);\n      }\n    }\n    now_beam\
    \ = next_beam;\n    best_state = now_beam.top();\n    if (best_state.is_finished())\
    \ break;\n  }\n  return best_state.root_action;\n}\n/**\n * @brief Beam Search\n\
    \ * @docs docs/heuristic/beam-search.md\n */\n"
  code: "#pragma once\n#include \"heuristic/time-keeper.hpp\"\n\ntemplate <class State>\n\
    int BeamSearch(const State& state, const int beam_width, int time_threshold) {\n\
    \  auto time_keeper = TimeKeeper(time_threshold);\n  priority_queue<State> now_beam;\n\
    \  State best_state;\n  now_beam.push(state);\n  for (int t = 0;; t++) {\n   \
    \ priority_queue<State> next_beam;\n    for (int i = 0; i < beam_width; i++) {\n\
    \      if (time_keeper.is_time_over()) return best_state.root_action;\n      if\
    \ (now_beam.empty()) break;\n      State now_state = now_beam.top();\n      now_beam.pop();\n\
    \      auto actions = now_state.next_actions();\n      for (const auto& action\
    \ : actions) {\n        State next_state = now_state;\n        next_state.advance(action);\n\
    \        next_state.eval_score();\n        if (t == 0) next_state.root_action\
    \ = action;\n        next_beam.push(next_state);\n      }\n    }\n    now_beam\
    \ = next_beam;\n    best_state = now_beam.top();\n    if (best_state.is_finished())\
    \ break;\n  }\n  return best_state.root_action;\n}\n/**\n * @brief Beam Search\n\
    \ * @docs docs/heuristic/beam-search.md\n */"
  dependsOn:
  - heuristic/time-keeper.hpp
  isVerificationFile: false
  path: heuristic/beam-search.hpp
  requiredBy: []
  timestamp: '2025-10-21 21:13:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/beam-search.hpp
layout: document
redirect_from:
- /library/heuristic/beam-search.hpp
- /library/heuristic/beam-search.hpp.html
title: Beam Search
---
## テンプレート

```
struct State {
  using score_t = double;

 private:
 public:
  score_t score = 0;
  int root_action = -1;
  State() {}

  bool is_finished() const {}
  void eval_score() { this->score = 0; }
  void advance(int action) {}
  vector<int> next_actions() const {}

  friend bool operator<(const State& lhs, const State& rhs) {
    return lhs.score < rhs.score;
  }
};
```