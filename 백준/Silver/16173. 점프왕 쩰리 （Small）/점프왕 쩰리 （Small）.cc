#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int n;
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs() {
  queue<pair<int, int>> q;

  q.push({0, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 2; i++) {
      int nx = cur.first + dx[i] * map[cur.first][cur.second];
      int ny = cur.second + dy[i] * map[cur.first][cur.second];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      if (visited[nx][ny])
        continue;

      q.push({nx, ny});
      visited[nx][ny] = true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  map.resize(n, vector<int>(n));
  visited.resize(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  bfs();

  if(visited[n-1][n-1]) cout << "HaruHaru";
  else cout << "Hing";

  return 0;
}