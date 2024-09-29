// 11053
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

  vector<int> inc(n, 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (v[i] > v[j])
        inc[i] = max(inc[i], inc[j] + 1);
    }
  }

  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    maxLen = max(maxLen, inc[i]);
  }

  cout << maxLen;

  return 0;
}