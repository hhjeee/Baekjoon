#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int arr[9] = {0};

void repetitionCombination(int cnt, int num) {
  if (cnt == m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = num; i < (int)v.size(); i++) {
    arr[cnt] = v[i];
    repetitionCombination(cnt + 1, i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  // 받은 수를 중복제거, 오름차순으로
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  // 중복조합
  repetitionCombination(0, 0);

  return 0;
}