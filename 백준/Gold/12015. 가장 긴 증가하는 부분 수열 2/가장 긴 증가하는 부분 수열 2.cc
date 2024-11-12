#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> sorted;
  sorted.push_back(v[0]);
  for (int i = 0; i < n; i++) {
    if (v[i] > sorted.back()) {
      sorted.push_back(v[i]);
    } else {
      int s = 0, e = sorted.size();
      while (s < e) {
        int mid = s + (e - s) / 2;
        if (sorted[mid] < v[i]) {
          s = mid + 1;
        } else {
          e = mid;
        }
      }
      sorted[s] = v[i];
    }
  }

  cout << sorted.size();

  return 0;
}