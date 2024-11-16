#include <iostream>
#include <vector>

using namespace std;
using vii = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int r, c, d;
  // 북, 동, 남, 서
  cin >> r >> c >> d;

  vector<vii> status(n + 1, vii(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> status[i][j];
    }
  }

  int count = 0;
  while (true) {
    if (status[r][c] == 0) {
      status[r][c] = 2;
      count++;
    }

    else if (status[r - 1][c] != 0 && status[r + 1][c] != 0 &&
             status[r][c + 1] != 0 && status[r][c - 1] != 0) {
      if (d == 0) {
        if (r + 1 < n && status[r + 1][c] != 1)
          r += 1;
        else
          break;
      } else if (d == 1) {
        if (c - 1 >= 0 && status[r][c - 1] != 1)
          c -= 1;
        else
          break;
      } else if (d == 2) {
        if (r - 1 >= 0 && status[r - 1][c] != 1)
          r -= 1;
        else
          break;
      } else if (d == 3) {
        if (c + 1 < m && status[r][c + 1] != 1)
          c += 1;
        else
          break;
      }
    }

    else if (status[r - 1][c] == 0 || status[r + 1][c] == 0 ||
             status[r][c + 1] == 0 || status[r][c - 1] == 0) {
      d -= 1;
      if (d == -1)
        d = 3;

      if (d == 0) {
        if (status[r - 1][c] == 0)
          r -= 1;
      } else if (d == 1) {
        if (status[r][c + 1] == 0)
          c += 1;
      } else if (d == 2) {
        if (status[r + 1][c] == 0)
          r += 1;
      } else if (d == 3) {
        if (status[r][c - 1] == 0)
          c -= 1;
      }
    }
  }

  cout << count;

  return 0;
}