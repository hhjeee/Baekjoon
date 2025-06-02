#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> parent;
vector<vector<int>> dist;

int find(int a) {
  if (parent[a] == a)
    return a;
  else
    return parent[a] = find(parent[a]);
}
void uni_on(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA != rootB) {
    parent[rootB] = rootA;
  }
}

void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
          continue;

        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int m;
  cin >> n >> m;

  parent.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  dist.resize(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    uni_on(a, b);

    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  floyd();

  vector<vector<int>> group(n + 1);
  for (int i = 1; i <= n; i++) {
    group[find(i)].push_back(i);
  }

  vector<int> answer;
  for (vector<int> g : group) {
    if (g.size() > 0) {
      int min_val = INT_MAX;
      int r = g[0];

      for (int i = 0; i < g.size(); i++) {
        int max_val = -1;
        for (int j = 0; j < g.size(); j++) {
          max_val = max(max_val, dist[g[i]][g[j]]);
        }

        if (min_val > max_val) {
          min_val = max_val;
          r = g[i];
        }
      }

      answer.push_back(r);
    }
  }

  cout << answer.size() << '\n';
  sort(answer.begin(), answer.end());
  for (int a : answer) {
    cout << a << '\n';
  }

  return 0;
}