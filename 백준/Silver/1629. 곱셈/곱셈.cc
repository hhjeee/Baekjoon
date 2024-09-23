#include <iostream>
using namespace std;
using ll = long long int;

ll power(ll a, ll b, ll c) {
  if (b == 1)
    return a % c;
  else if (b % 2 == 0) {
    ll tmp = power(a, b / 2, c);
    return tmp * tmp % c;
  } else {
    ll tmp = power(a, b - 1, c);
    return a * tmp % c;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;

  ll result = power(a, b, c);

  cout << result;

  return 0;
}