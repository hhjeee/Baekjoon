#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<char>> field(12, vector<char>(6));
vector<vector<bool>> visited(12, vector<bool>(6, false));
vector<pair<int, int>> group;
bool explode = false;
int chain = 0;

void dfs(int x, int y, char color) {
  visited[x][y] = true;
  group.push_back({x, y});

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
      continue;
    if (visited[nx][ny])
      continue;
    if (field[nx][ny] != color)
      continue;

    dfs(nx, ny, color);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 12; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 6; j++) {
      field[i][j] = s[j];
    }
  }

  while (1) {
    for (int i = 0; i < 12; i++)
      fill(visited[i].begin(), visited[i].end(), false);

    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        group.clear();
        if (field[i][j] != '.') {
          dfs(i, j, field[i][j]);

          if (group.size() >= 4) {
            for (auto e : group) {
              field[e.first][e.second] = '.';
              explode = true;
            }
          }
        }
      }
    }

    if (!explode)
      break;

    for (int j = 0; j < 6; j++) {
      queue<int> q;
      for (int i = 11; i >= 0; i--) {
        if (field[i][j] != '.')
          q.push(field[i][j]);
      }
      for (int i = 11; i >= 0; i--) {
        if (!q.empty()) {
          field[i][j] = q.front();
          q.pop();
        } else
          field[i][j] = '.';
      }
    }

    chain++;
    explode = false;
  }

  cout << chain;

  return 0;
}
