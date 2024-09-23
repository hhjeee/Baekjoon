#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int> > > edge(n + 1);

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    // 처음값 기준으로 우선순위 큐 정렬 -> 비용을 앞으로
    edge[from].push_back(make_pair(cost, to));
  }

  int a, b;
  cin >> a >> b;

  vector<int> distance(n + 1, INT_MAX);
  vector<int> pathReverse(n + 1, 0);
  distance[a] = 0;

  // 오름차순 정렬
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push(make_pair(0, a));

  while (!pq.empty()) {
    int tmpCost = pq.top().first;
    int tmpNode = pq.top().second;
    pq.pop();

    if (tmpCost > distance[tmpNode])
      continue;

    for (int i = 0; i < edge[tmpNode].size(); i++) {
      int tmpCost2 = tmpCost + edge[tmpNode][i].first; // + 거쳐가는 비용
      int tmpNode2 = edge[tmpNode][i].second;

      if (tmpCost2 < distance[tmpNode2]) {
        distance[tmpNode2] = tmpCost2;
        pathReverse[tmpNode2] = tmpNode;

        pq.push(make_pair(tmpCost2, tmpNode2));
      }
    }
  }

  // 최소비용
  cout << distance[b] << '\n';

  // 포함된 도시 개수(출발, 도착 포함)
  stack<int> path;
  path.push(b);

  int node = b;
  while (pathReverse[node] != 0) {
    path.push(pathReverse[node]);
    node = pathReverse[node];
  }

  cout << path.size() << '\n';

  // 도시 순서대로
  while (!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
  }

  return 0;
}