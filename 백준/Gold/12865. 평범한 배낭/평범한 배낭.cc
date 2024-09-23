#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k; // 물건수, 버틸수 있는 무게

  vector<int> bag(k + 1, 0);

  for (int i = 0; i < n; i++) {
    int w, v; // 무게, 가치
    cin >> w >> v;

    for (int j = k; j >= w; j--) {
      bag[j] = max(bag[j], bag[j - w] + v);
    }
  }

  cout << bag[k];

  return 0;
}