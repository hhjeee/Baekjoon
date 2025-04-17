#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int d[4] = {-3, -1, 1, 3};

string puzzle;
unordered_map<string, bool> visited;

int bfs() {
  queue<pair<string, int>> q;
  q.push({puzzle, 0});

  while (!q.empty()) {
    pair<string, int> cur = q.front();
    q.pop();

    if (cur.first == "123456780")
      return cur.second;

    if (visited[cur.first])
      continue;
    visited[cur.first] = true;

    int pos = cur.first.find('0');

    for (int i = 0; i < 4; i++) {
      int next = pos + d[i];

      if (next < 0 || next > 8)
        continue;
      if (d[i] == -1 && pos % 3 == 0)
        continue;
      if (d[i] == 1 && pos % 3 == 2)
        continue;

      string next_s = cur.first;
      next_s[pos] = next_s[next];
      next_s[next] = '0';

      q.push({next_s, cur.second + 1});
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 1; i <= 9; i++) {
    char c;
    cin >> c;
    puzzle += c;
  }

  cout << bfs();

  return 0;
}