#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> sensor(n);
  for (int i = 0; i < n; i++) {
    cin >> sensor[i];
  }

  sort(sensor.begin(), sensor.end());

  vector<int> gap;
  for (int i = 0; i < n - 1; i++) {
    gap.push_back(sensor[i + 1] - sensor[i]);
  }
  sort(gap.begin(), gap.end(), greater<int>());

  int result = sensor[n - 1] - sensor[0];
  for (int i = 0; i < k - 1 && i < n-1; i++) {
    result -= gap[i];
  }

  cout << result;

  return 0;
}