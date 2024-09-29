// 15686
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > houses;
  vector<pair<int, int> > chickens;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // 0 빈칸, 1 집 , 2 치킨집
      int num;
      cin >> num;
      if (num == 1)
        houses.push_back(make_pair(i, j));
      if (num == 2)
        chickens.push_back(make_pair(i, j));
    }
  }

  int chicken_count = chickens.size(); // 치킨집수
  vector<int> selected_chicken(chicken_count, 1);
  for (int i = 0; i < chicken_count - m; i++) {
    selected_chicken[i] = 0;
  }

  int min_cd = 999999;
  do {
    int sum = 0;

    for (int i = 0; i < houses.size(); i++) {
      int cd = 999999;
      for (int j = 0; j < chickens.size(); j++) {
        if (selected_chicken[j] == 1) {
          int chicken_distance = abs(houses[i].first - chickens[j].first) +
                                 abs(houses[i].second - chickens[j].second);
          cd = min(cd, chicken_distance);
        }
      }
      sum += cd;
    }

    min_cd = min(min_cd, sum);

  } while (next_permutation(selected_chicken.begin(), selected_chicken.end()));

  cout << min_cd;

  return 0;
}