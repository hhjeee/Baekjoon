#include <algorithm>
#include <iostream>
using namespace std;

char intToChar(int n) {
  if (n < 10)
    return n + '0';
  else
    return n - 10 + 'A';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, b;
  cin >> n >> b;

  string result = "";
  while (n) {
    result.push_back(intToChar(n % b));
    n = n / b;
  }

  reverse(result.begin(), result.end());

  cout << result;

  return 0;
}