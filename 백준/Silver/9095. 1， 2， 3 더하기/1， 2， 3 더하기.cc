#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  vector<int> sum(11, 0);
  sum[1] = 1;
  sum[2] = 2;
  sum[3] = 4;

  for (int i = 4; i <= 10; i++) {
    sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
  }

  while (t--) {
    int n;
    cin >> n;
    cout << sum[n] << '\n';
  }

  return 0;
}