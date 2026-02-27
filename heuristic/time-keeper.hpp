#pragma once

class TimeKeeper {
 private:
  chrono::high_resolution_clock::time_point start_time_;
  int time_threshold_;

 public:
  TimeKeeper(int time_threshold) : start_time_(chrono::high_resolution_clock::now()), time_threshold_(time_threshold) {}
  long long elapsed_ms() const {
    auto diff = chrono::high_resolution_clock::now() - this->start_time_;
    return chrono::duration_cast<chrono::milliseconds>(diff).count();
  }
  double elapsed_ratio() const {
    return (double)elapsed_ms() / time_threshold_;
  }
  bool is_time_over() const {
    return elapsed_ms() >= time_threshold_;
  }
};