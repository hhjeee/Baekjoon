#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> result;

bool checking_ok() {
  int val = 0;
  for (int i = 0; i < result.size(); ++i) {
    val = val * 10 + result[i];
  }

  if (val == 1)
    return false;

  for (int i = 2; i <= sqrt(val); ++i) {
    if (val % i == 0)
      return false;
  }

  return true;
}

void dfs() {
  if (result.size() == n) {
    if (checking_ok()) {
      for (int r : result) {
        cout << r;
      }
      cout << '\n';
    }
    return;
  }

  for (int i = 1; i <= 9; i++) {
    result.push_back(i);

    if (checking_ok())
      dfs();

    result.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  dfs();

  return 0;
}