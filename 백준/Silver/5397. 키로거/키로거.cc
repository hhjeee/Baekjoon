#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    list<char> l;
    auto idx = l.begin();

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        if (idx != l.begin())
          idx = l.erase(--idx);
      } else if (s[i] == '<') {
        if (idx != l.begin())
          idx--;
      } else if (s[i] == '>') {
        if (idx != l.end())
          idx++;
      } else {
        l.insert(idx, s[i]);
      }
    }

    for (auto c : l) {
      cout << c;
    }
    cout << '\n';
  }
  
      return 0;
}