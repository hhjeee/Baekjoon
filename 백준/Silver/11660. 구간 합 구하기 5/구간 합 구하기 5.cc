#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> table[i][j];
    }
  }

  vector<vector<long long int>> sum(n + 1, vector<long long int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == 1)
        sum[i][j] = table[i][j];
      else
        sum[i][j] = sum[i][j - 1] + table[i][j];
    }
  }

  // n이 1024, m이 100,000 nlogn
  // sum 최대 1024 * 1024 * 1000
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long int result = 0;
    for (int i = x1; i <= x2; i++) {
      result += (sum[i][y2] - sum[i][y1 - 1]);
    }

    cout << result << '\n';
  }

  return 0;
}