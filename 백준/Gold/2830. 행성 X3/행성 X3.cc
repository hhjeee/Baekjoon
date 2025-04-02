#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> names(n);
  for (int i = 0; i < n; i++) {
    cin >> names[i];
  }

  long long int result = 0;
  for (int i = 0; i < 21; i++) {
    // 2^20 = 1,048,576
    long long int count = 0;

    for (int j = 0; j < n; j++) {
      // names[j] 의 i번째 비트가 1인지 확인
      if (names[j] & (1 << i))
        count++;
    }

    result += count * (n - count) * (1ll << i);
  }

  cout << result;

  return 0;
}