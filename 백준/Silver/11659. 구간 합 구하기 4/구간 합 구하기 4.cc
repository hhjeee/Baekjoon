#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> nums(n);
  vector<int> sums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (i != 0)
      sums[i] = sums[i - 1] + nums[i];
    else
      sums[i] = nums[i];
  }

  while (m--) {
    int s, e;
    cin >> s >> e;

    if (s > 1)
      cout << sums[e - 1] - sums[s - 2] << '\n';
    else
      cout << sums[e - 1] << '\n';
  }

  return 0;
}