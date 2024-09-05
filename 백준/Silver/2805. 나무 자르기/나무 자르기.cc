// 2805
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int arr[1000001] = {0};
  int min = 2000000000;
  int max = 0;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    if (arr[i] < min)
      min = arr[i];
    if (arr[i] > max)
      max = arr[i];
  }

  int start = 0;
  int end = max;
  long long int mid = 0;
  long long int prev = 0;

  while (start <= end) {
    mid = start + (end - start) / 2;
    long long int height = 0;

    for (int j = 0; j < n; j++) {
      if (mid < arr[j])
        height += arr[j] - mid;
    }

    if (height < m) {
      end = mid - 1;
    } else {
      prev = mid;
      start = mid + 1;
    }
  }

  cout << prev;

  return 0;
}