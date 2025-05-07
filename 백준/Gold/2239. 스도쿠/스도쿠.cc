#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> zeros;

bool is_valid(int x, int y, int value) {
  // 행
  for (int i = 0; i < 9; i++) {
    if (board[x][i] == value)
      return false;
  }
  // 열
  for (int i = 0; i < 9; i++) {
    if (board[i][y] == value)
      return false;
  }

  // 3X3
  int rx = x / 3;
  int ry = y / 3;
  for (int i = rx * 3; i < rx * 3 + 3; i++) {
    for (int j = ry * 3; j < ry * 3 + 3; j++) {
      if (board[i][j] == value)
        return false;
    }
  }

  return true;
}

bool dfs(int idx) {
  if (idx == zeros.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << board[i][j];
      }
      cout << '\n';
    }
    return true;
  }

  int cx = zeros[idx].first;
  int cy = zeros[idx].second;

  for (int i = 1; i <= 9; i++) {
    if (is_valid(cx, cy, i)) {
      board[cx][cy] = i;
      if (dfs(idx + 1))
        return true;
      board[cx][cy] = 0;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  board.resize(9, vector<int>(9));
  for (int i = 0; i < 9; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; j++) {
      board[i][j] = s[j] - '0';
      if (board[i][j] == 0)
        zeros.push_back({i, j});
    }
  }

  dfs(0);

  return 0;
}