#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, result = 0;

bool checking_dialog(int depth, int i) {
  if (abs(depth - i) == abs(v[depth] - v[i]))
    return true;
  return false;
}
bool checking(int depth) {
  for (int i = 0; i < depth; i++) {
    // i는 비교할 row, depth는 현재 row
    if (v[i] == v[depth] || checking_dialog(depth, i)) {
      return false;
    }
  }
  return true;
}
void dfs(int depth) {
  if (depth == n) {
    result++;
    return; // 없으면 OOM
  }

  for (int i = 0; i < n; i++) {
    v[depth] = i;
    if (checking(depth))
      dfs(depth + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  v.resize(n);

  dfs(0);

  cout << result;

  return 0;
}