#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> in;
vector<vector<int>> out;
vector<bool> visited;
stack<int> s;

void dfs(int a) {
  visited[a] = true;
  s.push(a);

  for (auto next : out[a]) {
    if (!visited[next])
      dfs(next);
  }
}
void rev_dfs(int a) {
  visited[a] = true;
  s.push(a);

  for (auto prev : in[a]) {
    if (!visited[prev])
      rev_dfs(prev);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  in.resize(n + 1);
  out.resize(n + 1);
  visited.resize(n + 1, false);

  while (m--) {
    int a, b;
    cin >> a >> b;

    // a->b
    out[a].push_back(b);
    in[b].push_back(a);
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    fill(visited.begin(), visited.end(), false);
    s = stack<int>();

    dfs(i);
    int dfs_result = s.size();

    fill(visited.begin(), visited.end(), false);
    s = stack<int>();

    rev_dfs(i);
    int rev_dfs_result = s.size();

    if (dfs_result + rev_dfs_result == n + 1)
      count++;
  }

  cout << count;

  return 0;
}