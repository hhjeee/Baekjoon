#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool test(vector<int> homes, int min_dist, int c) {
  // min_dist = 가장 인접한 두 공유기 사이 거리

  // homes[0] 에 설치-> c--
  c--;

  int i = 0, j = 1;
  while (c > 0) {
    if (i == homes.size() - 1 || j >= homes.size()) {
      return false;
    }
    if (homes[i] + min_dist <= homes[j]) {
      c--;
      i = j;
    }
    j++;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, c;
  cin >> n >> c;

  vector<int> homes(n);
  for (int i = 0; i < n; i++) {
    cin >> homes[i];
  }
  sort(homes.begin(), homes.end()); // 오름차순 정렬

  // 가장 인접한 두 공유기 사이의 거리를 가능한 크게
  int min_dist = 1;
  int max_dist = homes[n - 1] - homes[0];
  int result = 0;
  while (min_dist <= max_dist) {
    int mid = (min_dist + max_dist) / 2;

    if (test(homes, mid, c)) {
      result = mid;
      min_dist = mid + 1;
    } else {
      max_dist = mid - 1;
    }
  }

  cout << result << '\n';

  return 0;
}