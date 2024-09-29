#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> city(n + 1, vector<int>(n + 1));
  int chicken_count = 0; // 치킨집수
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // 0 빈칸, 1 집 , 2 치킨집
      cin >> city[i][j];
      if (city[i][j] == 2) {
        city[i][j] = chicken_count + 2;
        chicken_count++;
      }
    }
  }

  vector<int> chicken(chicken_count, 1);
  for (int i = 0; i < chicken_count - m; i++) {
    chicken[i] = 0;
  }

  int min_cd = 999999;
  do {
    int sum = 0;
    vector<vector<int>> cd(n + 1, vector<int>(n + 1, 999999));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (city[i][j] == 1) {
          for (int k = 1; k <= n; k++) {
            for (int l = 1; l <= n; l++) {
              if (city[k][l] >= 2 && chicken[city[k][l] - 2] == 1) {
                int chicken_distance = abs(i - k) + abs(j - l);
                cd[i][j] = min(cd[i][j], chicken_distance);
              }
            }
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (city[i][j] == 1)
          sum += cd[i][j];
      }
    }
    min_cd = min(min_cd, sum);

  } while (next_permutation(chicken.begin(), chicken.end()));

  cout << min_cd;

  return 0;
}