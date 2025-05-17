#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  // dp[n] == n원을 만드는 방법 수
  vector<int> dp(k + 1, 0);
  dp[0] = 1; // 아무 동전도 사용하지 않음

  for (int i = 0; i < n; i++) {
    int coin = coins[i];
    for (int j = coin; j <= k; j++) {
      dp[j] += dp[j - coin];
    }
  }

  cout << dp[k] << '\n';

  return 0;
}