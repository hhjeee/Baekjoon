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

  vector<int> result;
  result.push_back(v[0]);

  for (int i = 1; i < v.size(); i++) {
    if (v[i] > result[result.size() - 1])
      result.push_back(v[i]);
    else {
      int idx =
          lower_bound(result.begin(), result.end(), v[i]) - result.begin();
      result[idx] = v[i];
    }
  }

  cout << result.size();

  return 0;
}