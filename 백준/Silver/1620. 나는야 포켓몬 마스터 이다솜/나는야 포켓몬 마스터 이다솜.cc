#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  unordered_map<string, int> um;
  unordered_map<int, string> rev_um;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    um[s] = i;
    rev_um[i] = s;
  }

  while (m--) {
    string s;
    cin >> s;

    if ((s[0] >= 65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122))
      cout << um[s] <<'\n';
    else
      cout << rev_um[stoi(s)]<<'\n';
  }

  return 0;
}