#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> table[i][j];
    }
  }

  vector<vector<long long int>> sum(n + 1, vector<long long int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + table[i][j];
    }
  }
  
  int k;
  cin >> k;

  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long int result =
        sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];

    cout << result << '\n';
  }

  return 0;
}