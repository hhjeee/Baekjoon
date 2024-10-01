#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int> > sea(n, vector<int>(n, 0));
  int shark_x, shark_y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> sea[i][j];
      if (sea[i][j] == 9) {
        shark_x = i;
        shark_y = j;
        sea[i][j] = 0;
      }
    }
  }

  int time = 0;
  int size = 2;
  int count = 0; // 같은 크기의 물고기 얼마나 먹었는지

  while (1) {
    vector<vector<int> > visited(n, vector<int>(n, 0));
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(shark_x, shark_y)));
    visited[shark_x][shark_y] = 1;

    int min_distance = 999999;
    pair<int, int> eat_fish = make_pair(-1, -1);

    while (!q.empty()) {
      pair<int, pair<int, int> > front_fish = q.front();
      int distance = front_fish.first;
      int x = front_fish.second.first;
      int y = front_fish.second.second;
      q.pop();

      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          // -1,0 / 1,0 / 0,-1 / 0,1
          if (abs(i) + abs(j) != 1)
            continue;

          int next_x = x + i;
          int next_y = y + j;

          if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n ||
              visited[next_x][next_y])
            continue;

          // 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없음
          if (sea[next_x][next_y] > size)
            continue;

          visited[next_x][next_y] = 1;
          q.push(make_pair(distance + 1, make_pair(next_x, next_y)));

          if (sea[next_x][next_y] > 0 && sea[next_x][next_y] < size) {
            if (distance + 1 < min_distance) {
              // 가장 가까운 거리
              min_distance = distance + 1;
              eat_fish = make_pair(next_x, next_y);
            } else if (distance + 1 == min_distance) {
              // 거리 같을때
              if (next_x < eat_fish.first ||
                  (next_x == eat_fish.first && next_y < eat_fish.second)) {
                eat_fish = make_pair(next_x, next_y);
              }
            }
          }
        }
      }
    }

    if (eat_fish == make_pair(-1, -1)) {
      break;
    }

    int fish_x = eat_fish.first;
    int fish_y = eat_fish.second;
    time += min_distance;
    sea[fish_x][fish_y] = 0;
    count++;

    // 크기 증가 체크
    if (count == size) {
      size++;
      count = 0;
    }

    shark_x = fish_x;
    shark_y = fish_y;
  }

  cout << time << '\n';
  return 0;
}
