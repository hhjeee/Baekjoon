#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}
void uni_on(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA != rootB)
    parent[rootB] = rootA;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  parent.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  while (m--) {
    int c, a, b;
    cin >> c >> a >> b;

    if (c) {
      if (find(a) == find(b))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      uni_on(a, b);
    }
  }

  return 0;
}