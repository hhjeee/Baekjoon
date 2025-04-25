#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

char inttoChar(int n) {
  if (n < 10)
    return n + '0';
  return n + 'A' - 10;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b, m;
  cin >> a >> b >> m;

  // a진법을 10진법으로
  int result = 0;
  while (m--) {
    int t;
    cin >> t;

    result = result * a + t;
  }

  // 10진법을 b진법으로
  stack<int> s;
  while (result) {
    s.push(result % b);
    result /= b;
  }

  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }

  return 0;
}