#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }

  // +, -, *, /
  vector<int> calculator(n);
  for (int i = 0; i < 4; i++) {
    cin >> calculator[i];
  }

  vector<int> arr;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < calculator[i]; j++) {
      arr.push_back(i);
    }
  }

  int max = -1000000000;
  int min = 1000000000;
  do {
    int next = num[0];

    for (int i = 0; i < n - 1; i++) {
      if (arr[i] == 0) {
        next = next + num[i + 1];
      } else if (arr[i] == 1) {
        next = next - num[i + 1];
      } else if (arr[i] == 2) {
        next = next * num[i + 1];
      } else if (arr[i] == 3) {
        next = next / num[i + 1];
      }
    }

    if (max < next)
      max = next;
    if (min > next)
      min = next;
  } while (next_permutation(arr.begin(), arr.end()));

  // 최대, 최소 출력
  cout << max << '\n' << min;
  return 0;
}