#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int chartoInt(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return c - 'A' + 10;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string n;
  int b;
  cin >> n >> b;

  int result = 0;
  for (char c : n) {
    result = result * b + chartoInt(c);
  }

  cout << result;

  return 0;
}