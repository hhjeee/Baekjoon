#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<bool> broken(10, false);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    broken[t] = true;
  }

  int result = abs(n - 100);
  for (int i = 0; i <= 1000000; i++) {
    string tmp = to_string(i);
    int len = tmp.length();

    bool flag = false;
    for (char c : tmp) {
      if (broken[c - '0']) {
        flag = true;
        break;
      }
    }

    if (!flag)
      result = min(result, abs(i - n) + len);
  }

  cout << result;

  return 0;
}