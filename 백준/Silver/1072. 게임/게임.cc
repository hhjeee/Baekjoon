#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int x, y;
  cin >> x >> y;

  long long int prev_z = ((long long)y * 100) / x; // y / x * 100

  if (prev_z >= 99) {
    cout << -1;
    return 0;
  }

  int left = 1, right = 1000000000;
  int answer = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    long long int new_z = ((long long)(y + mid) * 100) / (x + mid);

    if (new_z > prev_z) {
      answer = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }

  cout << answer;

  return 0;
}