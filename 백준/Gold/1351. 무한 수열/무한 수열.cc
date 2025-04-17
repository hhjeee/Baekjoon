#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<long long int, long long int> a;
int p, q;

long long int find_a(long long int n) {
  if (n == 0)
    return 1;
  else if (a.find(n) != a.end())
    return a[n];
  else
    return a[n] = find_a(n / p) + find_a(n / q);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long int n;
  cin >> n >> p >> q;

  cout << find_a(n);

  return 0;
}