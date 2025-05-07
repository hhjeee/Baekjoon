#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i + 1].find(nums[i]) == 0) {
        flag = true;
        break;
      }
    }

    cout << (flag ? "NO" : "YES") << '\n';
  }

  return 0;
}