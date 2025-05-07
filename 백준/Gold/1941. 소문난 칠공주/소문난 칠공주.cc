#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<char>> classroom;
vector<vector<bool>> visited(5, vector<bool>(5, false));
int result = 0;

bool is_connected(int sx, int sy, vector<vector<int>> &tmp) {
  queue<pair<int, int>> q;

  q.push({sx, sy});
  visited[sx][sy] = true;

  int count = 1;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
        continue;
      if (visited[nx][ny] || tmp[nx][ny] == 0)
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      count++;
    }
  }

  if (count == 7)
    return true;
  else
    return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  classroom.resize(5, vector<char>(5));
  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 5; j++) {
      classroom[i][j] = s[j];
    }
  }

  vector<int> selected(25, 0);
  for (int i = 18; i < 25; i++) {
    // 7명
    selected[i] = 1;
  }

  do {
    vector<vector<int>> tmp(5, vector<int>(5, 0));
    int count_s = 0;
    for (int i = 0; i < 25; i++) {
      if (selected[i] == 1) {
        tmp[i / 5][i % 5] = 1;
        if (classroom[i / 5][i % 5] == 'S')
          count_s++;
      }
    }

    if (count_s < 4)
      continue;

    visited.assign(5, vector<bool>(5, false));
    for (int i = 0; i < 25; i++) {
      if (selected[i] == 1) {
        if (is_connected(i / 5, i % 5, tmp))
          result++;
        break;
      }
    }
  } while (next_permutation(selected.begin(), selected.end()));

  cout << result;

  return 0;
}