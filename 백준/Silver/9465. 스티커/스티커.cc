#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int sticker[2][100001] = {0};

    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < n; k++) {
        cin >> sticker[j][k];
      }
    }

    for (int j = 0; j < n; j++) {
      if (j == 0)
        continue;
      if (j == 1) {
        sticker[0][j] = sticker[1][0] + sticker[0][j];
        sticker[1][j] = sticker[0][0] + sticker[1][j];
      } else {
        sticker[0][j] =
            max(sticker[1][j - 1], sticker[1][j - 2]) + sticker[0][j];
        sticker[1][j] =
            max(sticker[0][j - 1], sticker[0][j - 2]) + sticker[1][j];
      }
    }

    cout << max(sticker[0][n - 1], sticker[1][n - 1]) << '\n';
  }

  return 0;
}