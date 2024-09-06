// 6064
#include <algorithm>
#include <iostream>
using namespace std;

int GCD(int a, int b) {
  int n;
  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}
int LCM(int a, int b) { return a * b / GCD(a, b); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int ans = -1;

    for (int j = y; j <= LCM(M, N); j += N) {
      if (j % M == x % M && j % N == y % N) {
        ans = j;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}