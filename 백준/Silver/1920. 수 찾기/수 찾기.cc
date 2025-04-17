#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n;

  unordered_map<int, int> um;
  while (n--) {
    int t;
    cin >> t;
    um[t] = 1;
  }

  cin >> m;
  while (m--) {
    int t;
    cin >> t;
    if (um.find(t) != um.end())
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }

  return 0;
}