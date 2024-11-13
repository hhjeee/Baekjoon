#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int> > bingo(5, vector<int>(5, 0));
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> bingo[i][j];
    }
  }

  int bingo_count = 0;
  for (int i = 1; i < 26; i++) {
    int answer;
    cin >> answer;

    // 해당 값 찾기
    int x, y;
    for (int j = 0; j < 5; j++) {
      if (find(bingo[j].begin(), bingo[j].end(), answer) != bingo[j].end()) {
        y = find(bingo[j].begin(), bingo[j].end(), answer) - bingo[j].begin();
        bingo[j][y] = 0;
        x = j;
      }
    }

    // 빙고 검사
    // 가로
    int count = 0;
    for (int j = 0; j < 5; j++) {
      if (bingo[x][j] == 0)
        count++;
      if (count == 5)
        bingo_count++;
    }

    // 세로
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (bingo[j][y] == 0)
        count++;
      if (count == 5)
        bingo_count++;
    }

    // 대각선
    if (x == y) {
      count = 0;
      for (int j = 0; j < 5; j++) {
        if (bingo[j][j] == 0)
          count++;
        if (count == 5)
          bingo_count++;
      }
    }
    if (x + y == 4) {
      count = 0;
      for (int j = 0; j < 5; j++) {
        if (bingo[j][4 - j] == 0)
          count++;
        if (count == 5)
          bingo_count++;
      }
    }

    if (bingo_count >= 3) {
      cout << i;
      break;
    }
  }

  return 0;
}