#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> solution(n);
  for (int i = 0; i < n; i++) {
    cin >> solution[i];
  }

  int s = 0, e = n - 1;
  int result_sum = INT_MAX;

  pair<int, int> result_pair;

  while (s < e) {
    int tmp_sum = solution[s] + solution[e];

    if (abs(tmp_sum) <= abs(result_sum)) {
      result_sum = tmp_sum;
      result_pair = make_pair(solution[s], solution[e]);
    }

    if (tmp_sum < 0) {
      s++;
    } else {
      e--;
    }
  }

  cout << result_pair.first << ' ' << result_pair.second;

  return 0;
}