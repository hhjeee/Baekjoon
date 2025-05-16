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

int count_safe(vector<vector<int>> &map) {
  queue<pair<int, int>> q;
  vector<vector<int>> time(n, vector<int>(n, -1));

  for (auto v : real_virus) {
    q.push({v.first, v.second});
    time[v.first][v.second] = 0;
    map[v.first][v.second] = 3;
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.second + dx[i];
      int ny = cur.first + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (map[ny][nx] == 1 || time[ny][nx] != -1)
        continue;

      if (map[ny][nx] == 0 || map[ny][nx] == 2) {
        time[ny][nx] = time[cur.first][cur.second] + 1;
        q.push({ny, nx});
      }
    }
  }

  int max_time = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 0 && time[i][j] == -1)
        return -1;

      if (map[i][j] == 0)
        max_time = max(max_time, time[i][j]);
    }
  }

  return max_time;
}
void dfs(int virus, int idx, vector<vector<int>> map) {
  if (virus == m) {
    vector<vector<int>> tmp = map;
    int time = count_safe(tmp);
    if (time == -1)
      return;
    else
      result = min(result, time);
    return;
  }

  for (int i = idx; i < viruses.size(); i++) {
    int x = viruses[i].first;
    int y = viruses[i].second;

    real_virus.push_back({x, y});

    dfs(virus + 1, i + 1, map);

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