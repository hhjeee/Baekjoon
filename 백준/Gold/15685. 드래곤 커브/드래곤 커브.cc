#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> map(101, vector<int>(101, false));

int find_squares() {
  int count = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
        count++;
      }
    }
  }
  return count;
}
void dragon_curve(int x, int y, int d, int g) {
  vector<int> dir;
  dir.push_back(d);

  // 현재 세대 선 개수 = 누적 * 2
  for (int gen = 1; gen <= g; gen++) {
    for (int i = dir.size() - 1; i >= 0; i--) {
      int tmp = (dir[i] + 1) % 4; // 90도 회전
      dir.push_back((tmp));
    }
  }

  map[y][x] = true;
  for (int i = 0; i < dir.size(); i++) {
    x += dx[dir[i]];
    y += dy[dir[i]];
    if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
      map[y][x] = true;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;

    dragon_curve(x, y, d, g);
  }

  cout << find_squares();

  return 0;
}
