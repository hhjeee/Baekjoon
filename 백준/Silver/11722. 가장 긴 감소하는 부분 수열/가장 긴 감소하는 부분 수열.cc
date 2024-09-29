// 11722
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> dec(n, 1);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (v[i] > v[j])
        dec[i] = max(dec[i], dec[j] + 1);
    }
  }

  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    maxLen = max(maxLen, dec[i]);
  }

  cout << maxLen;

  return 0;
}