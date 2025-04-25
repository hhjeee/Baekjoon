#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int r, c;
vector<vector<char>> board;
int result = 0;

void dfs(int x, int y, int visited, int length) {
  result = max(result, length);

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
      continue;

    if (visited & (1 << (board[nx][ny] - 'A')))
      continue;

    dfs(nx, ny, visited | (1 << (board[nx][ny] - 'A')), length + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c;

  board.resize(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < c; j++) {
      board[i][j] = tmp[j];
    }
  }

  int visited = 0;
  visited |= (1 << (board[0][0] - 'A'));
  dfs(0, 0, visited, 1);

  cout << result;

  return 0;
}