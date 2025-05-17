#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct tree {
  int x, y, age;
};
bool compare(tree a, tree b) { return a.age < b.age; }

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> ground(n, vector<int>(n, 5));
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // 양분
      cin >> a[i][j];
    }
  }

  vector<vector<deque<int>>> trees(n, vector<deque<int>>(n));
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    trees[x - 1][y - 1].push_back(z);
  }

  for (int year = 0; year < k; year++) {
    vector<vector<deque<int>>> dead_trees(n, vector<deque<int>>(n));

    // 봄
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        deque<int> dq;
        for (int age_idx = 0; age_idx < trees[i][j].size(); age_idx++) {
          int cur_age = trees[i][j][age_idx];
          if (ground[i][j] >= cur_age) {
            ground[i][j] -= cur_age;
            dq.push_back(cur_age + 1);
          } else {
            dead_trees[i][j].push_back(cur_age);
          }
        }
        trees[i][j] = dq;
      }
    }

    // 여름
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int age : dead_trees[i][j]) {
          ground[i][j] += (age / 2);
        }
      }
    }

    // 가을
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int age : trees[i][j]) {
          if (age % 5 == 0) {
            for (int d = 0; d < 8; d++) {
              int nx = i + dx[d];
              int ny = j + dy[d];

              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
              trees[nx][ny].push_front(1);
            }
          }
        }
      }
    }

    // 겨울
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ground[i][j] += a[i][j];
      }
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      count += trees[i][j].size();
    }
  }
  cout << count;

  return 0;
}