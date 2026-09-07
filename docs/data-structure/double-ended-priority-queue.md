C++ の `priority_queue` では max のみ取得できるが，min も取得できるようにしたデータ構造．


https://natsugiri.hatenablog.com/entry/2016/10/10/035445

Interval-heap



stack を 2 本持って deque を作る手法を応用しても作れるが，分割で priority queue 内部を見ないと線形にできないのが面倒．