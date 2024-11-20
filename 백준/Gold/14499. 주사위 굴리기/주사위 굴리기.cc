#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, x, y, k;
  cin >> n >> m >> y >> x >> k;

  vector<vi> map(n, vi(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  // 주사위
  // 위복동서남밑
  int dice[6] = {0, 0, 0, 0, 0, 0};
  //   2
  // 4 1 3
  //   5
  //   6

  int direction;
  for (int i = 0; i < k; i++) {
    // 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
    cin >> direction;

    int dice_copy[6];
    for (int j = 0; j < 6; j++) {
      dice_copy[j] = dice[j];
    }

    bool next = false;
    if (direction == 1) {
      if (x + 1 < m) {
        x += 1;
        dice[2] = dice_copy[0];
        dice[5] = dice_copy[2];
        dice[3] = dice_copy[5];
        dice[0] = dice_copy[3];
        next = true;
      }
    } else if (direction == 2) {
      if (x - 1 >= 0) {
        x -= 1;
        dice[3] = dice_copy[0];
        dice[5] = dice_copy[3];
        dice[2] = dice_copy[5];
        dice[0] = dice_copy[2];
        next = true;
      }
    } else if (direction == 3) {
      if (y - 1 >= 0) {
        y -= 1;
        dice[1] = dice_copy[0];
        dice[5] = dice_copy[1];
        dice[4] = dice_copy[5];
        dice[0] = dice_copy[4];
        next = true;
      }
    } else if (direction == 4) {
      if (y + 1 < n) {
        y += 1;
        dice[4] = dice_copy[0];
        dice[5] = dice_copy[4];
        dice[1] = dice_copy[5];
        dice[0] = dice_copy[1];
        next = true;
      }
    }

    if (next && x >= 0 && x < m && y >= 0 && y < n) {
      if (map[y][x] == 0) {
        map[y][x] = dice[5];
      } else {
        dice[5] = map[y][x];
        map[y][x] = 0;
      }

      cout << dice[0] << '\n';
    }
  }

  return 0;
}