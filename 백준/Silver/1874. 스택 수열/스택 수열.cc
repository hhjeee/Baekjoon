#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int arr[100001] = {
      0,
  };
  stack<int> st;
  queue<char> q;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  st.push(1);

  int a = 2;
  int idx = 0;

  while (idx < n && a <= n + 1) {
    if (!st.empty()) {
      if (st.top() == arr[idx]) {
        st.pop();
        idx++;

        q.push('-');
      } else {
        st.push(a);
        a++;

        q.push('+');
      }
    } else {
      st.push(a);
      a++;

      q.push('+');
    }
  }

  if (st.empty()) {
    cout << '+' << '\n'; // 1 push
    while (!q.empty()) {
      cout << q.front() << '\n';
      q.pop();
    }
  } else {
    cout << "NO";
  }

  return 0;
}