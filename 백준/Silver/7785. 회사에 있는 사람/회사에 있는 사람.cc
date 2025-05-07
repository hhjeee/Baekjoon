#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<string, string, greater<string>> m;

  while (n--) {
    string n, s;
    cin >> n >> s;

    m[n] = s;
  }

  for (auto t : m) {
    if (t.second == "enter")
      cout << t.first << '\n';
  }

  return 0;
}