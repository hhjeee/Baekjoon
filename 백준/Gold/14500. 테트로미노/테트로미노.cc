#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int arr[501][501] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  // 가로 일자블록
  int max1 = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m - 3; j++) {
      sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
      if (sum > max1)
        max1 = sum;
    }
  }

  // 세로 일자블록
  int max2 = 0;
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n - 3; j++) {
      sum = arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i];
      if (sum > max2)
        max2 = sum;
    }
  }

  // 정사각형
  //   int max3 = 0;
  //   for (int i = 0; i < n - 1; i++) {
  //     int sum = 0;
  //     for (int j = 0; j < n - 1; j++) {
  //       sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
  //       if (sum > max3)
  //         max3 = sum;
  //     }
  //   }

  // 3+1 모양(3이 가로)
  int max4 = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m - 2; j++) {
      int three = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];

      int one = 0;
      if (i == 0)
        one = max(max(arr[i + 1][j], arr[i + 1][j + 1]), arr[i + 1][j + 2]);
      else if (i == n - 1)
        one = max(max(arr[i - 1][j], arr[i - 1][j + 1]), arr[i - 1][j + 2]);
      else
        one = max(max(max(arr[i - 1][j], arr[i - 1][j + 1]),
                      max(arr[i - 1][j + 2], arr[i + 1][j])),
                  max(arr[i + 1][j + 1], arr[i + 1][j + 2]));

      sum = three + one;
      if (sum > max4)
        max4 = sum;
    }
  }
  // 3+1 모양(3이 세로)
  int max5 = 0;
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n - 2; j++) {
      int three = arr[j][i] + arr[j + 1][i] + arr[j + 2][i];

      int one = 0;
      if (i == 0)
        one = max(max(arr[j][i + 1], arr[j + 1][i + 1]), arr[j + 2][i + 1]);
      else if (i == m - 1)
        one = max(max(arr[j][i - 1], arr[j + 1][i - 1]), arr[j + 2][i - 1]);
      else
        one = max(max(max(arr[j][i + 1], arr[j + 1][i + 1]),
                      max(arr[j + 2][i + 1], arr[j][i - 1])),
                  max(arr[j + 1][i - 1], arr[j + 2][i - 1]));

      sum = three + one;
      if (sum > max5)
        max5 = sum;
    }
  }

  // 2+2 가로
  int max6 = 0;
  for (int i = 0; i < n - 1; i++) {
    int sum = 0;
    for (int j = 0; j < m - 1; j++) {
      int tmp = arr[i][j] + arr[i][j + 1];

      int tmp2 = 0;
      if (j == 0)
        tmp2 = max(arr[i + 1][j] + arr[i + 1][j + 1],
                   arr[i + 1][j + 1] + arr[i + 1][j + 2]);
      else if (j == n - 2)
        tmp2 = max(arr[i + 1][j - 1] + arr[i + 1][j],
                   arr[i + 1][j] + arr[i + 1][j + 1]);
      else
        tmp2 = max(max(arr[i + 1][j + 1] + arr[i + 1][j + 2],
                       arr[i + 1][j - 1] + arr[i + 1][j]),
                   arr[i + 1][j] + arr[i + 1][j + 1]);

      sum = tmp + tmp2;
      if (sum > max6)
        max6 = sum;
    }
  }
  // 2+2 세로
  int max7 = 0;
  for (int i = 0; i < n - 1; i++) {
    int sum = 0;
    for (int j = 0; j < m - 1; j++) {
      int tmp = arr[i][j] + arr[i + 1][j];

      int tmp2;
      if (i == 0)
        tmp2 = max(arr[i][j + 1] + arr[i + 1][j + 1],
                   arr[i + 1][j + 1] + arr[i + 2][j + 1]);
      else if (i == n - 2)
        tmp2 = max(arr[i][j + 1] + arr[i + 1][j + 1],
                   arr[i - 1][j + 1] + arr[i][j + 1]);
      else
        tmp2 = max(max(arr[i + 1][j + 1] + arr[i + 2][j + 1],
                       arr[i][j + 1] + arr[i + 1][j + 1]),
                   arr[i - 1][j + 1] + arr[i][j + 1]);

      sum = tmp + tmp2;
      if (sum > max7)
        max7 = sum;
    }
  }

  //   cout << max1 << ' ' << max2 << ' ' << max3 << ' ' << max4 << ' ' << max5
  //        << ' ' << max6 << ' ' << max7;

  int result = max(max(max(max1, max2), max(max4, max5)), max(max6, max7));
  cout << result;

  return 0;
}