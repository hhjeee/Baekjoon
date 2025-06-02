#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

bool compare(tuple<int, int, char> t1, tuple<int, int, char> t2) {
  if (get<1>(t1) == get<1>(t2))
    return get<0>(t1) < get<0>(t2);
  return get<1>(t1) < get<1>(t2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, char>> result;
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;

    result.push_back(make_tuple(a, b, c));
  }

  sort(result.begin(), result.end(), compare);

  for (auto t : result) {
    cout << get<2>(t);
  }

  return 0;
}