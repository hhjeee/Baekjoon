#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;

  vector<vector<int>> dist(v + 1, vector<int>(v + 1, INT_MAX));
  for (int i = 1; i <= v; i++) {
    dist[i][i] = 0;
  }

  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for (int k = 1; k <= v; k++) {
    for (int i = 1; i <= v; i++) {
      for (int j = 1; j <= v; j++) {
        if (i == k || k == j)
          continue;
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
          continue;

        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  int result = INT_MAX;
  for (int i = 1; i <= v; i++) {
    for (int j = i + 1; j <= v; j++) {
      if (dist[i][j] == INT_MAX || dist[j][i] == INT_MAX)
        continue;
      result = min(result, dist[i][j] + dist[j][i]);
    }
  }

  if (result == INT_MAX)
    cout << -1;
  else
    cout << result;

  return 0;
}