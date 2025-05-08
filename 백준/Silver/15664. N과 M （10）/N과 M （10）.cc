#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
vector<int> result;

void dfs(int idx, int len) {
  if (len == m) {
    for (int a : result) {
      cout << a << ' ';
    }
    cout << '\n';

    return;
  }

  int prev = -1;
  for (int i = idx + 1; i < n; i++) {
    if (v[i] == prev)
      continue;
    prev = v[i];

    result.push_back(v[i]);

    dfs(i, len + 1);

    result.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }

  sort(v.begin(), v.end());

  dfs(-1, 0);

  return 0;
}