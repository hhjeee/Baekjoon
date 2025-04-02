#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int INF = 10000000;
int n;
vector<vector<int>> w;
vector<vector<int>> dp;

int tsp(int cur, int visited) {
  if (visited == (1 << n) - 1) {
    if (w[cur][1] == 0)
      return INF;
    else
      return w[cur][1];
  }

  if (dp[cur][visited] != -1) {
    return dp[cur][visited];
  }
  dp[cur][visited] = INF;

  for (int next = 1; next <= n; next++) {
    int nextIndex = 1 << (next - 1);
    if ((visited & nextIndex) == 0 && w[cur][next] != 0) {
      dp[cur][visited] =
          min(dp[cur][visited], w[cur][next] + tsp(next, visited | nextIndex));
    }
  }

  return dp[cur][visited];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  w.resize(n + 1, vector<int>(n + 1));
  dp.resize(n + 1, vector<int>(1 << n, -1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> w[i][j];
    }
  }

  cout << tsp(1, 1);

  return 0;
}