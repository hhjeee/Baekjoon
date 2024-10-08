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

  q.push(n);
  visited[n] = 1;

  while (visited[k] == 0) {
    int tmp = q.front();
    q.pop();

    if (tmp * 2 <= 100000 && visited[tmp * 2] == 0) {
      q.push(tmp * 2);
      visited[tmp * 2] = visited[tmp]+1;
    }

    if (tmp - 1 >= 0 && visited[tmp - 1] == 0) {
      q.push(tmp - 1);
      visited[tmp - 1] = visited[tmp] + 1;
    }

    if (tmp + 1 <= 100000 && visited[tmp + 1] == 0) {
      q.push(tmp + 1);
      visited[tmp + 1] = visited[tmp] + 1;
    }
  }

  cout << visited[k] - 1;
  return 0;
}