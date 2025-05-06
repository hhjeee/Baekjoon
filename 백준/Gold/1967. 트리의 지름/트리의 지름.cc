#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
  int to, cost;
};

int n;
vector<vector<edge>> edgeList;
vector<int> visited;
int max_val = 0;

void dfs(int cur, int sum) {
  visited[cur] = true;

  for (auto next : edgeList[cur]) {
    if (!visited[next.to]) {
      dfs(next.to, sum + next.cost);
    }
  }

  max_val = max(max_val, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  edgeList.resize(n + 1);
  visited.resize(n + 1, false);

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edgeList[a].push_back({b, c});
    edgeList[b].push_back({a, c});
  }

  for (int i = 1; i <= n; i++) {
    visited.clear();
    visited.resize(n + 1, false);
    dfs(i, 0);
  }

  cout << max_val;

  return 0;
}