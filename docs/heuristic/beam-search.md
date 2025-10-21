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