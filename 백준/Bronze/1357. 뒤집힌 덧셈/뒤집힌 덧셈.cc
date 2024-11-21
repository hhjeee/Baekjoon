#include <iostream>
#include <vector>
using namespace std;

string rev(string x) {
  string copy = x;
  for (int i = 0; i < x.length(); i++) {
    x[i] = copy[x.length() - i - 1];
  }

  int start = 0;
  while (start < x.length() && x[start] == '0') {
    start++;
  }
  return x.substr(start);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string x, y;
  cin >> x >> y;
    
  cout << rev(to_string((stoi(rev(x)) + stoi(rev(y)))));

  return 0;
}