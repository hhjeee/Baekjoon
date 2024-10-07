#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t, n, m;
  cin >> t >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  // 각 배열 내 원소 가능한 합 값 계산
  unordered_map<ll, ll> sumA;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      sumA[sum]++;
    }
  }
  unordered_map<ll, ll> sumB;
  for (int i = 0; i < m; i++) {
    ll sum = 0;
    for (int j = i; j < m; j++) {
      sum += b[j];
      sumB[sum]++;
    }
  }

  ll count = 0;
  for (auto i = sumA.begin(); i != sumA.end(); i++) {
    ll key_a = i->first;
    ll find = t - key_a;

    if (sumB.find(find) != sumB.end()) {
      count += sumA[key_a] * sumB[find];
    }
  }

  cout << count << '\n';

  return 0;
}