#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void bfs_no(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});

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

      if (grid[cur.first][cur.second] == grid[nx][ny]) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}
void bfs_yes(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});

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

      if (grid[cur.first][cur.second] == 'B') {
        if (grid[nx][ny] == 'B') {
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      } else {
        if (grid[nx][ny] == 'R' || grid[nx][ny] == 'G') {
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  grid.resize(n, vector<char>(n));
  visited.resize(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      grid[i][j] = s[j];
    }
  }

  int count_no = 0, count_yes = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        count_no++;
        bfs_no(i, j);
      }
    }
  }

  visited.clear();
  visited.resize(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        count_yes++;
        bfs_yes(i, j);
      }
    }
  }

  cout << count_no << ' ' << count_yes;

  return 0;
}