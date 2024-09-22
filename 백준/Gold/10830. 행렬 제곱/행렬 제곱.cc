// 10830
#include <iostream>
#include <vector>
using namespace std;
using matrixType = vector<vector<int> >;

matrixType multiplyMatrix(matrixType matrix1, matrixType matrix2, int n) {
  matrixType tmp(n, vector<int>(n, 0)); // n x n, 0으로 초기화

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        tmp[i][j] += matrix1[i][k] * matrix2[k][j];
        tmp[i][j] %= 1000;
      }
    }
  }

  return tmp;
}
matrixType powerMatrix(matrixType matrix, int n, long long int b) {
  if (b == 1)
    return matrix;
  else if (b % 2 == 0) {
    matrixType tmp = powerMatrix(matrix, n, b / 2);
    return multiplyMatrix(tmp, tmp, n);
  } else {
    matrixType tmp2 = powerMatrix(matrix, n, b - 1);
    return multiplyMatrix(matrix, tmp2, n);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  long long int b;
  cin >> n >> b; // 행렬 n의 b제곱

  matrixType matrix(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tmp;
      cin >> tmp;
      if (tmp >= 1000)
        tmp %= 1000;
      matrix[i][j] = tmp;
    }
  }

  matrixType result = powerMatrix(matrix, n, b);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}