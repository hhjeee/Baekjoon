#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<vector<int>>> cctv_dirs = {
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}};

int n, m;
vector<vector<int>> office;
vector<tuple<int, int, int>> cctv;
int result = INT_MAX;

void fill(vector<vector<int>> &tmp_office, int x, int y, vector<int> dirs) {
  for (int dir : dirs) {
    int nx = x;
    int ny = y;
    while (1) {
      nx += dx[dir];
      ny += dy[dir];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n)
        break;
      if (tmp_office[ny][nx] == 6)
        break;

      if (tmp_office[ny][nx] == 0)
        tmp_office[ny][nx] = -1;
    }
  }
}
void dfs(int depth, vector<vector<int>> tmp_office) {
  if (depth == cctv.size()) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (tmp_office[i][j] == 0)
          count++;
      }
    }
    result = min(result, count);
    return;
  }

  int v = get<0>(cctv[depth]);
  int y = get<1>(cctv[depth]);
  int x = get<2>(cctv[depth]);

  for (auto dirs : cctv_dirs[v - 1]) {
    vector<vector<int>> tmp = tmp_office;
    fill(tmp, x, y, dirs);
    dfs(depth + 1, tmp);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  office.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> office[i][j];
      if (office[i][j] >= 1 && office[i][j] <= 5) {
        cctv.push_back(make_tuple(office[i][j], i, j));
      }
    }
  }

  dfs(0, office);

  cout << result;

  return 0;
}