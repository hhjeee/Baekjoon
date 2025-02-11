#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int LOG = 16;

int n;
vector<int> depth;
vector<vector<int>> parent;
vector<vector<pair<int, int>>> adjList;
vector<vector<pair<int, int>>> min_max;

void bfs() {
  int root = 1;

  queue<int> q;
  vector<bool> visited(n + 1, false);
  q.push(root);

  depth[root] = 0;
  visited[root] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto next : adjList[cur]) {
      int next_node = next.first;
      int cost = next.second;

      if (!visited[next_node]) {
        visited[next_node] = true;
        q.push(next_node);

        parent[0][next_node] = cur;
        min_max[0][next_node] = {cost, cost};
        depth[next_node] = depth[cur] + 1;
      }
    }
  }
}
void find_ancestors() {
  for (int k = 1; k <= LOG; k++) {
    for (int v = 1; v <= n; v++) {
      parent[k][v] = parent[k - 1][parent[k - 1][v]];

      int min_t =
          min(min_max[k - 1][v].first, min_max[k - 1][parent[k - 1][v]].first);
      int max_t = max(min_max[k - 1][v].second,
                      min_max[k - 1][parent[k - 1][v]].second);

      min_max[k][v] = {min_t, max_t};
    }
  }
}
pair<int, int> find_LCA_cost(int a, int b) {
  // 항상 b를 끌어올리도록 swap
  if (depth[a] > depth[b]) {
    int tmp = b;
    b = a;
    a = tmp;
  }

  int min_cost = 1000001, max_cost = 0;

  // b를 a까지 끌어올리기
  for (int k = LOG; k >= 0; k--) {
    if (depth[b] - depth[a] >= (1 << k)) {
      min_cost = min(min_cost, min_max[k][b].first);
      max_cost = max(max_cost, min_max[k][b].second);

      b = parent[k][b];
    }
  }

  if (a == b)
    return {min_cost, max_cost};

  for (int k = LOG; k >= 0; k--) {
    if (parent[k][a] != parent[k][b]) {
      min_cost = min(min_cost, min(min_max[k][a].first, min_max[k][b].first));
      max_cost = max(max_cost, max(min_max[k][a].second, min_max[k][b].second));

      a = parent[k][a];
      b = parent[k][b];
    }
  }

  min_cost = min(min_cost, min(min_max[0][a].first, min_max[0][b].first));
  max_cost = max(max_cost, max(min_max[0][a].second, min_max[0][b].second));

  return {min_cost, max_cost};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  depth.resize(n + 1);
  parent.resize(LOG + 1, vector<int>(n + 1, 0));
  adjList.resize(n + 1);

  min_max.resize(LOG + 1, vector<pair<int, int>>(n + 1, {1000001, 0}));

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }

  // depth 구하기
  bfs();

  // 조상 구하기
  find_ancestors();

  int m;
  cin >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;

    // LCA 찾기
    pair<int, int> result = find_LCA_cost(a, b);
    cout << result.first << ' ' << result.second << '\n';
  }

  return 0;
}
