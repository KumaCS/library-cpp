#pragma once

class TimeKeeper {
 private:
  chrono::high_resolution_clock::time_point start_time_;
  int time_threshold_;

 public:
  TimeKeeper(int time_threshold) : start_time_(chrono::high_resolution_clock::now()), time_threshold_(time_threshold) {}
  bool is_time_over() const {
    auto diff = chrono::high_resolution_clock::now() - this->start_time_;
    return chrono::duration_cast<chrono::milliseconds>(diff).count() >= time_threshold_;
  }
};