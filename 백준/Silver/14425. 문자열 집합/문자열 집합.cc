#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  unordered_map<string, int> um;

  while (n--) {
    string s;
    cin >> s;
    um[s] = 1;
  }

  int count = 0;
  while (m--) {
    string s;
    cin >> s;
    if (um[s])
      count++;
  }

  cout << count;

  return 0;
}