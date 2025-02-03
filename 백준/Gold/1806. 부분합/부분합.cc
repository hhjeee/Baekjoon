#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, s;
  cin >> n >> s;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int left = 0, right = 0;
  int subtotal = 0;

  int ans = 100001;

  while (1) {
    if (subtotal < s) {
      if (right == n)
        break;
      subtotal += v[right];
      right++;
    } else {
      ans = min(ans, right - left);
      subtotal -= v[left];
      left++;
    }
  }

  int result = (ans == 100001) ? 0 : ans;
  cout << result;

  return 0;
}