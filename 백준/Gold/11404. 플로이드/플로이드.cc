#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int distance[102][102];
  fill_n(&distance[0][0], 102 * 102, 987654321);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    distance[a][b] = distance[a][b] ? min(distance[a][b], c) : c;
  }

  // 거쳐가는 노드 고려해서 갱신
  for (int i = 1; i <= n; i++) { // 거쳐가는 노드
    for (int j = 1; j <= n; j++) {
      if (j == i)
        continue;
      for (int k = 1; k <= n; k++) {
        if (k == i || j == k)
          continue;

        distance[j][k] = min(distance[j][k], distance[j][i] + distance[i][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      distance[i][j] = distance[i][j] == 987654321 ? 0 : distance[i][j];
      cout << distance[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}