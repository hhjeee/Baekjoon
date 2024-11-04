#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

bool compare(pii a, pii b) { return a.first > b.first; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pii> univ(n);
  for (int i = 0; i < n; i++) {
    int p, d;
    cin >> p >> d;
    univ.push_back({p, d});
  }
  sort(univ.begin(), univ.end(), compare); // p 내림차순

  int sum = 0;
  int check[10001] = {0};
  for (int i = 0; i < n; i++) {
    int idx = univ[i].second;

    if (check[idx] == 0) {
      sum += univ[i].first;
      check[idx] = 1;
    } else {
      for (int j = idx - 1; j >= 1; j--) {
        if (check[j] == 0) {
          check[j] = 1;
          sum += univ[i].first;
          break;
        }
      }
    }
  }

  cout << sum;

  return 0;
}