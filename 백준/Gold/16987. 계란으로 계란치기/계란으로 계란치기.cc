#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct info {
  int in, w;
};

int n;
vector<info> eggs;
vector<bool> broken;
int broken_eggs = 0;

void dfs(int idx, int cnt) {
  if (idx == n) {
    broken_eggs = max(broken_eggs, cnt);
    return;
  }
  if (broken[idx]) {
    dfs(idx + 1, cnt);
    return;
  }

  bool hit = false;

  for (int i = 0; i < n; i++) {
    if (broken[i] || idx == i)
      continue;

    hit = true;

    bool broken_idx = false, broken_i = false;
    eggs[idx].in -= eggs[i].w;
    eggs[i].in -= eggs[idx].w;
    if (eggs[idx].in <= 0) {
      cnt += 1;
      broken[idx] = true;
      broken_idx = true;
    }
    if (eggs[i].in <= 0) {
      cnt += 1;
      broken[i] = true;
      broken_i = true;
    }

    dfs(idx + 1, cnt);

    eggs[idx].in += eggs[i].w;
    eggs[i].in += eggs[idx].w;
    if (broken_idx) {
      cnt -= 1;
      broken[idx] = false;
    }
    if (broken_i) {
      cnt -= 1;
      broken[i] = false;
    }
  }

  if (!hit) {
    dfs(idx + 1, cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  eggs.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> eggs[i].in >> eggs[i].w;
  }

  broken.resize(n, false);
  dfs(0, 0);

  cout << broken_eggs;

  return 0;
}