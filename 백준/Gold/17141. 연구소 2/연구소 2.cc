#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
vector<pair<int, int>> viruses;
vector<pair<int, int>> real_virus;
int result = INT_MAX;

int count_virus(vector<vector<int>> &map) {
  queue<pair<int, int>> q;

  for (auto v : real_virus) {
    q.push({v.first, v.second});
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.second + dx[i];
      int ny = cur.first + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (map[ny][nx] == 1)
        continue;

      if (map[ny][nx] == 0 || map[ny][nx] == 2) {
        map[ny][nx] = map[cur.first][cur.second] + 1;
        q.push({ny, nx});
      }
    }
  }

  int time = 0;
  // 모든칸 못하면 -1
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 0 || map[i][j] == 2)
        return -1;
      time = max(time, map[i][j]);
    }
  }

  return time - 3;
}
void dfs(int virus, int idx, vector<vector<int>> map) {
  if (virus == m) {
    vector<vector<int>> tmp = map;

    int count = count_virus(tmp);
    if (count == -1)
      return;
    else
      result = min(result, count);
    return;
  }

  for (int i = idx; i < viruses.size(); i++) {
    int x = viruses[i].first;
    int y = viruses[i].second;

    map[x][y] = 3;
    real_virus.push_back({x, y});

    dfs(virus + 1, i + 1, map);

    map[x][y] = 2;
    real_virus.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2)
        viruses.push_back({i, j});
    }
  }

  dfs(0, 0, map);
  cout << (result == INT_MAX ? -1 : result);

  return 0;
}