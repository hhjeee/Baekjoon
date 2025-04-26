#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
vector<vector<int>> map;

int bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  q.push({sx, sy});
  visited[sx][sy] = true;
  map[sx][sy] = 0;

  int count = 1;

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

      if (map[nx][ny] == 1) {
        count++;
        q.push({nx, ny});
        visited[nx][ny] = true;
        map[nx][ny] = 0;
      }
    }
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  map.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      map[i][j] = s[j] - '0';
    }
  }

  vector<int> count_list;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1) {
        count_list.push_back(bfs(i, j));
      }
    }
  }

  sort(count_list.begin(), count_list.end());

  cout << count_list.size() << '\n';
  for (int n : count_list) {
    cout << n << '\n';
  }

  return 0;
}