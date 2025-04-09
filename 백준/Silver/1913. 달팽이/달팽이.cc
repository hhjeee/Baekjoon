#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> snail(n, vector<int>(n, 0));

  int value = n * n;
  int x = 0, y = 0;
  int d = 0;
  while (value) {
    snail[x][y] = value--;

    int next_x = x + dx[d];
    int next_y = y + dy[d];

    if (next_x == n || next_y == n || next_x == -1 || next_y == -1 ||
        snail[next_x][next_y] != 0) {
      d = (d + 1) % 4;
    }

    x += dx[d];
    y += dy[d];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << snail[j][i] << ' ';
    }
    cout << '\n';
  }

  int k;
  cin >> k;

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (snail[x][y] == k) {
        cout << y+1 << ' ' << x+1;
        break;
      }
    }
  }

  return 0;
}