#include <iostream>
using namespace std;
using ll = long long int;
int r = 1000000007;

pair<ll, ll> fibonacci(ll n) { // n, n-1 fibo 반환
  if (n == 1)
    return make_pair(1, 0);

  pair<ll, ll> tmp = fibonacci(n / 2);
  ll t1 = tmp.first;  // fibo(n)
  ll t2 = tmp.second; // fibo(n-1)
  ll t3 = (t1 + t2) % r;

  if (n % 2 == 0) {
    return make_pair(((t1 * t2) % r + (t1 * t3) % r) % r,
                     ((t1 * t1) % r + (t2 * t2) % r) % r);
  } else
    return make_pair((((t1 * t1) % r + (t3 * t3) % r) % r),
                     (((t1 * t2) % r + (t1 * t3) % r) % r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  cout << fibonacci(n).first;

  return 0;
}