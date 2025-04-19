#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> weight(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    weight[i][i] = 0;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    weight[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == k || k == j)
          continue;
        if (weight[i][k] == INT_MAX || weight[k][j] == INT_MAX)
          continue;

        if (weight[i][j] > weight[i][k] + weight[k][j])
          weight[i][j] = weight[i][k] + weight[k][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    int count = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;
      if (weight[i][j] != INT_MAX || weight[j][i] != INT_MAX)
        count++;
    }
    cout << n - 1 - count << '\n';
  }

  return 0;
}