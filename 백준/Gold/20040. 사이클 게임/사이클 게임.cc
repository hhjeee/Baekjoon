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
int uni_on(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA != rootB) {
    parent[rootB] = rootA;
    return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  parent.resize(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  int result = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;

    if (uni_on(a, b) && !result)
      result = i;
  }

  cout << result;

  return 0;
}