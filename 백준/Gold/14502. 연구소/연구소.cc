#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
vector<pair<int, int>> virus;
int result = 0;

int count_safe(vector<vector<int>> &tmp_map) {
  queue<pair<int, int>> q;

  for (auto v : virus)
    q.push({v.first, v.second});

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.second + dx[i];
      int ny = cur.first + dy[i];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        continue;
      if (tmp_map[ny][nx] == 1)
        continue;

      if (tmp_map[ny][nx] == 0) {
        tmp_map[ny][nx] = 2;
        q.push({ny, nx});
      }
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tmp_map[i][j] == 0)
        count++;
    }
  }
  return count;
}
void dfs(int wall, vector<vector<int>> map) {
  if (wall == 3) {
    vector<vector<int>> tmp = map;
    result = max(result, count_safe(tmp));
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        map[i][j] = 1;
        dfs(wall + 1, map);
        map[i][j] = 0;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2)
        virus.push_back({i, j});
    }
  }

  dfs(0, map);
  cout << result;

  return 0;
}