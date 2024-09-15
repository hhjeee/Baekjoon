#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    int n, m, w; // 지점, 도로, 웜홀
    cin >> n >> m >> w;

    vector<vector<pair<int, int>>> edge(n + 1);

    // 도로 정보
    for (int j = 0; j < m; j++) {
      int s, e, t; // from, to, 이동시간
      cin >> s >> e >> t;

      edge[s].push_back(make_pair(e, t));
      edge[e].push_back(make_pair(s, t));
    }
    // 웜홀 정보
    for (int j = 0; j < w; j++) {
      int s, e, t; // from, to, 줄어드는시간
      cin >> s >> e >> t;

      edge[s].push_back(make_pair(e, -t));
    }

    bool negative_cycle = false;
    // 모든 노드가 시작지점이 될 수 있음 !!!
    for (int start = 1; start <= n; start++) {
      vector<int> distance(n + 1, INT_MAX);
      distance[start] = 0;

      for (int j = 1; j < n; j++) { // n-1번 반복
        bool updated = false;
        for (int k = 1; k <= n; k++) {
          if (distance[k] == INT_MAX)
            continue;
          for (auto &e : edge[k]) {
            int v = e.first;
            int cost = e.second;
            if (distance[v] > distance[k] + cost) {
              distance[v] = distance[k] + cost;
              updated = true;
            }
          }
        }
        if (!updated)
          break;
      }

      // 음의 사이클 검사
      for (int j = 1; j <= n; j++) {
        if (distance[j] == INT_MAX)
          continue;
        for (auto &e : edge[j]) {
          int v = e.first;
          int cost = e.second;
          if (distance[v] > distance[j] + cost) {
            negative_cycle = true;
            break;
          }
        }
        if (negative_cycle)
          break;
      }
      if (negative_cycle)
        break;
    }

    cout << (negative_cycle ? "YES" : "NO") << '\n';
  }

  return 0;
}
