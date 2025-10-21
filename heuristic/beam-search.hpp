#pragma once
#include "heuristic/time-keeper.hpp"

template <class State>
int BeamSearch(const State& state, const int beam_width, int time_threshold) {
  auto time_keeper = TimeKeeper(time_threshold);
  priority_queue<State> now_beam;
  State best_state;
  now_beam.push(state);
  for (int t = 0;; t++) {
    priority_queue<State> next_beam;
    for (int i = 0; i < beam_width; i++) {
      if (time_keeper.is_time_over()) return best_state.root_action;
      if (now_beam.empty()) break;
      State now_state = now_beam.top();
      now_beam.pop();
      auto actions = now_state.next_actions();
      for (const auto& action : actions) {
        State next_state = now_state;
        next_state.advance(action);
        next_state.eval_score();
        if (t == 0) next_state.root_action = action;
        next_beam.push(next_state);
      }
    }
    now_beam = next_beam;
    best_state = now_beam.top();
    if (best_state.is_finished()) break;
  }
  return best_state.root_action;
}
/**
 * @brief Beam Search
 * @docs docs/heuristic/beam-search.md
 */