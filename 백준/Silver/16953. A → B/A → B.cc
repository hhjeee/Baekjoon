#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;

  int count = 1;
  while (1) {
    if (b == a)
      break;
    if (b < a) {
      count = -1;
      break;
    }

    if (b % 10 == 1) {
      b = b / 10;
    } else if (b % 2 == 0) {
      b = b / 2;
    } else {
      count = -1;
      break;
    }

    count++;
  }

  cout << count;

  return 0;
}