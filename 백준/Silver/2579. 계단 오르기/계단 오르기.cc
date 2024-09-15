#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int stair[301] = {0};
  int dp[301] = {0};

  for (int i = 0; i < n; i++) {
    cin >> stair[i];
  }

  dp[0] = stair[0];
  dp[1] = stair[0] + stair[1];

  for (int i = 2; i < n; i++) {
    dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
  }
  cout << dp[n - 1];

  return 0;
}