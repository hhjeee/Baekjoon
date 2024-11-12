#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> solution(n);
  for (int i = 0; i < n; i++) {
    cin >> solution[i];
  }
  sort(solution.begin(), solution.end()); // 오름차순 정렬

  ll result_sum = LLONG_MAX;
  ll a, b, c;
  for (int i = 0; i < n - 2; i++) {
    int s = i + 1;
    int e = n - 1;

    while (s < e) {
      ll tmp_sum = solution[i] + solution[s] + solution[e];

      if (abs(tmp_sum) <= abs(result_sum)) {
        result_sum = tmp_sum;
        a = solution[i];
        b = solution[s];
        c = solution[e];
      }

      if (tmp_sum < 0) {
        s++;
      } else {
        e--;
      }
    }
  }

  cout << a << ' ' << b << ' ' << c;

  return 0;
}