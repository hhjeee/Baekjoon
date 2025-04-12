#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct corn {
  int x, y, value;
};
struct compare {
  bool operator()(corn a, corn b) { return a.value < b.value; }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m, k;
vector<vector<int>> map;
priority_queue<corn, vector<corn>, compare> pq;
vector<vector<bool>> visited;

void bfs() {
  int count = 0;
  while (!pq.empty()) {
    corn top = pq.top();
    pq.pop();

    cout << top.x << ' ' << top.y << '\n';

    count++;
    if (count == k)
      break;

    for (int i = 0; i < 4; i++) {
      int next_x = top.x + dx[i];
      int next_y = top.y + dy[i];

      if (next_x < 1 || next_x > n || next_y < 1 || next_y > m)
        continue;
      if (visited[next_x][next_y])
        continue;

      pq.push({next_x, next_y, map[next_x][next_y]});
      visited[next_x][next_y] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  map.resize(n + 1, vector<int>(m + 1));
  visited.resize(n + 1, vector<bool>(m + 1, false));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[i][j];
      if (i == 1 || i == n || j == 1 || j == m) {
        pq.push({i, j, map[i][j]});
        visited[i][j] = true;
      }
    }
  }

  cin >> k;

  bfs();

  return 0;
}