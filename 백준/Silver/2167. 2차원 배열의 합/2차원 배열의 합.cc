#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;

  vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> sum = arr;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }

  cin >> k;

  while (k--) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;

    int result = 0;
    for (int t = i; t <= x; t++) {
      result += (sum[t][y] - sum[t][j - 1]);
    }

    cout << result << '\n';
  }

  return 0;
}