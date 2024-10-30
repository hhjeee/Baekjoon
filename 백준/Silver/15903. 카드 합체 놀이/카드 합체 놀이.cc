#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<ll> card(n);
  for (int i = 0; i < n; i++) {
    cin >> card[i];
  }

  for (int i = 0; i < m; i++) {
    sort(card.begin(), card.end());
    ll sum = card[0] + card[1];
    card[0] = sum;
    card[1] = sum;
  }

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += card[i];
  }

  cout << sum;

  return 0;
}