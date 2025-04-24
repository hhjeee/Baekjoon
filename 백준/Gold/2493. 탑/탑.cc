#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> top(n + 1, 0);
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> top[i];
  }

  vector<int> result(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && top[s.top()] < top[i]) {
      s.pop();
    }

    if (!s.empty())
      result[i] = s.top();

    s.push(i);
  }

  for (int i = 1; i <= n; i++) {
    cout << result[i] << ' ';
  }

  return 0;
}