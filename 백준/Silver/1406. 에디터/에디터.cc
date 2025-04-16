#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  list<char> l;
  for (char c : s)
    l.push_back(c);

  int m;
  cin >> m;
  cin.ignore();

  auto cursor = l.end();
  cursor--;
  cursor++;
  while (m--) {
    string c;
    getline(cin, c);

    if (c == "L") {
      if (cursor != l.begin())
        cursor--;
    }
    if (c == "D") {
      if (cursor != l.end())
        cursor++;
    }
    if (c == "B") {
      if (cursor != l.begin()) {
        cursor--;
        cursor = l.erase(cursor);
      }
    }
    if (c[0] == 'P') {
      l.insert(cursor, c[2]);
    }
  }

  for (auto i : l) {
    cout << i;
  }

  return 0;
}