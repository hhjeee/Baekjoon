#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
  int to, cost;
};
struct compare {
  bool operator()(edge a, edge b) { return a.cost > b.cost; }
};

int n;
vector<vector<edge>> edgeList;
vector<int> dist;
vector<vector<int>> table;

void dijkstra(int start) {
  dist[start] = 0;

  priority_queue<edge, vector<edge>, compare> pq;
  vector<bool> visited(n + 1, false);

  pq.push({start, dist[start]});

  while (!pq.empty()) {
    edge cur = pq.top();
    pq.pop();

    if (visited[cur.to])
      continue;
    visited[cur.to] = true;

    for (edge next : edgeList[cur.to]) {
      if (dist[next.to] > dist[cur.to] + next.cost) {
        if (cur.to == start)
          table[start][next.to] = next.to;
        else
          table[start][next.to] = table[start][cur.to];

        dist[next.to] = dist[cur.to] + next.cost;
        pq.push({next.to, dist[next.to]});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int m;
  cin >> n >> m;

  edgeList.resize(n + 1);
  dist.resize(n + 1, INT_MAX);
  table.resize(n + 1, vector<int>(n + 1, 0));
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    edgeList[a].push_back({b, c});
    edgeList[b].push_back({a, c});
  }

  for (int i = 1; i <= n; i++) {
    dist.clear();
    dist.resize(n + 1, INT_MAX);
    dijkstra(i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        cout << '-' << ' ';
      else
        cout << table[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}