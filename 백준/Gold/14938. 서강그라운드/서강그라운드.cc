// 14938
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, r;
  cin >> n >> m >> r;

  vector<int> item(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> item[i];
  }

  vector<vector<pair<int, int> > > graph(n + 1);
  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    graph[a].push_back(make_pair(b, l));
    graph[b].push_back(make_pair(a, l));
  }

   int maxItem = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> distance(n + 1, INT_MAX);
        distance[i] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 거리 기준 정렬
        pq.push(make_pair(0, i));

        while (!pq.empty()) {
            int curDistance = pq.top().first;
            int curRegion = pq.top().second;
            pq.pop();

            for (int j = 0; j < graph[curRegion].size(); j++) {
                int nextRegion = graph[curRegion][j].first;
                int nextLength = graph[curRegion][j].second;

                if (curDistance + nextLength < distance[nextRegion]) {
                    distance[nextRegion] = curDistance + nextLength;
                    pq.push(make_pair(distance[nextRegion], nextRegion));
                }
            }
        }

        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (distance[j] <= m) {
                count += item[j];
            }
        }

        maxItem = max(maxItem, count);
    }

    cout << maxItem << '\n';

    return 0;
}
