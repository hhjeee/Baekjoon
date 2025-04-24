#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, h;
vector<vector<bool>> lines;

int find_destination(int num) {
  for (int i = 1; i <= h; i++) {
    if (num < n && lines[i][num]) {
      num++;
    } else if (num > 0 && lines[i][num - 1]) {
      num--;
    }
  }

  return num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int m;
  cin >> n >> m >> h;

  lines.resize(h + 1, vector<bool>(n, false));
  while (m--) {
    int a, b;
    cin >> a >> b;

    lines[a][b] = true;
  }

  bool all_self = true;
  for (int k = 1; k <= n; k++) {
    if (find_destination(k) != k) {
      all_self = false;
      break;
    }
  }
  if (all_self) {
    cout << 0;
    return 0;
  }

  // 추가 가능한 자리 저장
  vector<pair<int, int>> can;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < n; j++) {
      if (lines[i][j])
        continue;
      if ((j > 1 && lines[i][j - 1]) || (j < n - 1 && lines[i][j + 1]))
        continue;

      can.push_back({i, j});
    }
  }
  
  if(can.size() == 0) {
      cout << -1;
      return 0;
  }

  // 1개 추가
  for (auto p : can) {
    lines[p.first][p.second] = true;

    bool all_self = true;
    for (int k = 1; k <= n; k++) {
      if (find_destination(k) != k) {
        all_self = false;
        break;
      }
    }
    if (all_self) {
      cout << 1;
      return 0;
    }

    lines[p.first][p.second] = false;
  }
  
  if(can.size() == 1) {
      cout << -1;
      return 0;
  }

  // 2개 추가
  int can_size = can.size();
  vector<int> tmp(can_size, 0);
  tmp[can_size - 1] = 1;
  tmp[can_size - 2] = 1;

  do {
    vector<pair<int, int>> change;
    for (int i = 0; i < can_size; i++) {
      if (tmp[i]) {
        lines[can[i].first][can[i].second] = true;
        change.push_back({can[i].first, can[i].second});
      }
    }

    // 인접 체크
    if (change[0].first == change[1].first &&
        abs(change[0].second - change[1].second) == 1) {
      for (auto p : change) {
        lines[p.first][p.second] = false;
      }
      continue;
    }

    bool all_self = true;
    for (int k = 1; k <= n; k++) {
      if (find_destination(k) != k) {
        all_self = false;
        break;
      }
    }
    if (all_self) {
      cout << 2;
      return 0;
    }

    for (auto p : change) {
      lines[p.first][p.second] = false;
    }
  } while (next_permutation(tmp.begin(), tmp.end()));

  if(can_size == 2) {
      cout << -1;
      return 0;
  }
  
  // 3개 추가
  fill(tmp.begin(), tmp.end(), 0);
  tmp[can_size - 1] = 1;
  tmp[can_size - 2] = 1;
  tmp[can_size - 3] = 1;

  do {
    vector<pair<int, int>> change;
    for (int i = 0; i < can_size; i++) {
      if (tmp[i]) {
        lines[can[i].first][can[i].second] = true;
        change.push_back({can[i].first, can[i].second});
      }
    }

    // 인접 체크
    bool invalid = false;
    for (int a = 0; a < change.size(); a++) {
      for (int b = a + 1; b < change.size(); b++) {
        if (change[a].first == change[b].first &&
            abs(change[a].second - change[b].second) == 1) {
          invalid = true;
          break;
        }
      }
    }
    if (invalid) {
      for (auto p : change) {
        lines[p.first][p.second] = false;
      }
      continue;
    }

    bool all_self = true;
    for (int k = 1; k <= n; k++) {
      if (find_destination(k) != k) {
        all_self = false;
        break;
      }
    }
    if (all_self) {
      cout << 3;
      return 0;
    }

    for (auto p : change) {
      lines[p.first][p.second] = false;
    }
  } while (next_permutation(tmp.begin(), tmp.end()));

  cout << -1;

  return 0;
}