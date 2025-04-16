#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs(int start_x, int start_y, int count) {
  queue<pair<int, int>> q;

  q.push({start_x, start_y});
  map[start_x][start_y] = count;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = cur.first + dx[i];
      int next_y = cur.second + dy[i];

      if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
        continue;
      if (visited[next_x][next_y])
        continue;

      if (map[next_x][next_y] == 1) {
        q.push({next_x, next_y});
        visited[next_x][next_y] = true;
        map[next_x][next_y] = count;
      }
    }
  }
}
int count_nums(int count) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == count)
        sum++;
    }
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  map.resize(n, vector<int>(n));
  visited.resize(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < n; j++) {
      map[i][j] = tmp[j] - 48;
    }
  }

  int count = 2;
  vector<int> result;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] == 1) {
        bfs(i, j, count);
        count;
        result.push_back(count_nums(count++));
      } else
        visited[i][j] = true;
    }
  }

  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for (int t : result)
    cout << t << '\n';

  return 0;
}