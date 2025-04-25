#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
vector<vector<int>> safe;
vector<vector<bool>> visited;

void bfs(int sx, int sy) {
  queue<pair<int, int>> q;

  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (visited[nx][ny])
        continue;

      if (safe[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  vector<vector<int>> map(n, vector<int>(n));
  int min_val = 101, max_val = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      min_val = min(min_val, map[i][j]);
      max_val = max(max_val, map[i][j]);
    }
  }

  int result = 1;
  for (int k = min_val; k <= max_val; k++) {
    safe.clear();
    visited.clear();
    safe.resize(n, vector<int>(n, false));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map[i][j] > k)
          safe[i][j] = true;
      }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j] && safe[i][j]) {
          count++;
          bfs(i, j);
        }
      }
    }

    result = max(result, count);
  }

  cout << result;

  return 0;
}