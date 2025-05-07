#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int l, c;
vector<char> al;
vector<char> password;
vector<bool> visited;

bool is_mo(char t) {
  if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u')
    return true;
  else
    return false;
}
void dfs(int idx, int len) {
  if (len == l) {
    int mo = 0, ja = 0;
    for (char t : password) {
      if (is_mo(t))
        mo++;
      else
        ja++;
    }

    //  최소 모음 한개, 자음 두개
    if (mo > 0 && ja > 1) {
      for (char t : password)
        cout << t;
      cout << '\n';
    }
    return;
  }

  for (int i = idx; i < c; i++) {
    if (visited[i])
      continue;

    password.push_back(al[i]);
    visited[i] = true;

    dfs(i + 1, len + 1);

    password.pop_back();
    visited[i] = false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> l >> c;

  al.resize(c);
  visited.resize(c);
  for (int i = 0; i < c; i++) {
    cin >> al[i];
  }

  sort(al.begin(), al.end());

  dfs(0, 0);

  return 0;
}