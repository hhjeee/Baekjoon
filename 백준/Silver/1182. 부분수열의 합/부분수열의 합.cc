#include <iostream>
#include <vector>
using namespace std;

int n, s;
vector<int> v;
int cnt = 0;

void dfs(int idx, int sum) {
  if (idx == n) {
    if (sum == s)
      cnt++;
    return;
  }

  // 현재 idx 선택
  dfs(idx + 1, sum + v[idx]);
  // 현재 idx 선택X
  dfs(idx + 1, sum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  dfs(0, 0);

  // 크기가 양수인 부분수열
  if (s == 0)
    cnt--;

  cout << cnt;

  return 0;
}