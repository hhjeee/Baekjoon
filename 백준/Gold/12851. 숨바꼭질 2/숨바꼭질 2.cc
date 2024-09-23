#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  queue<int> q;
  int visited[100001] = {0};
  int count[100001] = {0};

  q.push(n);
  visited[n] = 1;
  count[n] = 1;

  while (!q.empty()) {
    int tmp = q.front();
    q.pop();

    if (tmp * 2 <= 100000) {
      if (visited[tmp * 2] == 0) {
        q.push(tmp * 2);
        visited[tmp * 2] = visited[tmp] + 1;
        count[tmp * 2] = count[tmp];
      } else if (visited[tmp * 2] == visited[tmp] + 1)
        count[tmp * 2] += count[tmp];
    }

    if (tmp - 1 >= 0) {
      if (visited[tmp - 1] == 0) {
        q.push(tmp - 1);
        visited[tmp - 1] = visited[tmp] + 1;
        count[tmp - 1] = count[tmp];
      } else if (visited[tmp - 1] == visited[tmp] + 1)
        count[tmp - 1] += count[tmp];
    }

    if (tmp + 1 <= 100000) {
      if (visited[tmp + 1] == 0) {
        q.push(tmp + 1);
        visited[tmp + 1] = visited[tmp] + 1;
        count[tmp + 1] = count[tmp];
      } else if (visited[tmp + 1] == visited[tmp] + 1)
        count[tmp + 1] += count[tmp];
    }
  }

  cout << visited[k] - 1 << '\n' << count[k];

  return 0;
}