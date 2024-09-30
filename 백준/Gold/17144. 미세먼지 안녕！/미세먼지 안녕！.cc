// 17144
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int R, C, T;
  cin >> R >> C >> T;

  vector<vector<int> > A(R, vector<int>(C, 0));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> A[i][j];
      // 공기청정기는 항상 1번 열, 2개의 행 차지
    }
  }

  vector<vector<int> > tmp(R, vector<int>(C, 0));
  for (int t = 0; t < T; t++) {

    // 확산
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        int count = 0;
        if (A[i][j] > 0) {
          if (i > 0 && A[i - 1][j] != -1) {
            tmp[i - 1][j] += A[i][j] / 5;
            count++;
          }
          if (j + 1 < C && A[i][j + 1] != -1) {
            tmp[i][j + 1] += A[i][j] / 5;
            count++;
          }
          if (j > 0 && A[i][j - 1] != -1) {
            tmp[i][j - 1] += A[i][j] / 5;
            count++;
          }
          if (i + 1 < R) {
            tmp[i + 1][j] += A[i][j] / 5;
            count++;
          }

          tmp[i][j] += (A[i][j] - A[i][j] / 5 * count);
        }
      }
    }

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (A[i][j] != -1)
          A[i][j] = tmp[i][j];
      }
    }

    // 공기청정기 [idx][0] , [idx+1][0]
    int idx;
    for (int i = 0; i < R; i++) {
      if (A[i][0] == -1) {
        idx = i;
        break;
      }
    }

    tmp = A;

    for (int i = 1; i < C - 1; i++) {
      A[idx][i + 1] = tmp[idx][i];
      A[idx + 1][i + 1] = tmp[idx + 1][i];
    }
    A[idx][1] = 0;
    A[idx + 1][1] = 0;

    for (int i = idx; i > 0; i--) {
      A[i - 1][C - 1] = tmp[i][C - 1];
    }
    for (int i = idx + 1; i < R - 1; i++) {
      A[i + 1][C - 1] = tmp[i][C - 1];
    }

    for (int i = C - 1; i > 0; i--) {
      A[0][i - 1] = tmp[0][i];
      A[R - 1][i - 1] = tmp[R - 1][i];
    }

    for (int i = 0; i < idx - 1; i++) {
      A[i + 1][0] = tmp[i][0];
    }
    for (int i = R - 1; i > idx + 2; i--) {
      A[i - 1][0] = tmp[i][0];
    }

    tmp.assign(R, vector<int>(C, 0));
  }

  int sum = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (A[i][j] != -1)
        sum += A[i][j];
    }
  }

  cout << sum;

  return 0;
}
