#pragma once

vector<string> split(const string& s, char delimiter) {
  vector<string> ret(1);
  for (char c : s) {
    if (c == delimiter)
      ret.emplace_back();
    else
      ret.back().push_back(c);
  }
  return ret;
}
