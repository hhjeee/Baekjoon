#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
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

  if (ans == 100001)
    cout << 0;
  else
    cout << ans;

  return 0;
}