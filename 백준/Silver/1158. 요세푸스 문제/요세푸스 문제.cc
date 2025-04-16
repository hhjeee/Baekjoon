#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  queue<int> q;
  for (int i = 1; i <= n; i++)
    q.push(i);

  cout << "<";

  while (!q.empty()) {
    int tmp = k;
    while (tmp--) {
      int front = q.front();
      q.pop();
      if (tmp)
        q.push(front);
      else
        cout << front;
    }
    if (!q.empty())
      cout << ", ";
  }

  cout << ">";

  return 0;
}