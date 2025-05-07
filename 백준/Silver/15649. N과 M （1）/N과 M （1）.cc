#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> visited;
vector<int> nums;

void dfs(int start, int len) {
  if (len == m) {
    for (int t : nums)
      cout << t << ' ';
    cout << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;

    nums.push_back(i);
    visited[i] = true;

    dfs(i, len + 1);

    nums.pop_back();
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    visited.clear();
    visited.resize(n + 1, false);
    nums.clear();

    visited[i] = true;
    nums.push_back(i);
    dfs(i, 1);
  }

  return 0;
}