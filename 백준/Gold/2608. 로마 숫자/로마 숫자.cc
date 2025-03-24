#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string to_roma(int val) {
  // V, L, D는 한 번만 사용할 수 있고 I, X, C, M은 연속해서 세 번
  // IV 와 IX 는 같이 쓸 수 없으며 XL 과 XC, CD 와 CM 또한 같이 쓸 수 없다

  vector<pair<int, string>> roma_num = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

  string result = "";

  for (pair<int, string> n : roma_num) {
    while (val >= n.first) {
      result += n.second;
      val -= n.first;
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  map<string, int> m;
  m["I"] = 1;
  m["V"] = 5;
  m["X"] = 10;
  m["L"] = 50;
  m["C"] = 100;
  m["D"] = 500;
  m["M"] = 1000;
  m["IV"] = 4;
  m["IX"] = 9;
  m["XL"] = 40;
  m["XC"] = 90;
  m["CD"] = 400;
  m["CM"] = 900;

  string a;
  string b;

  cin >> a >> b;

  // a, b 계산
  int a_val = 0;
  int b_val = 0;

  for (int i = 0; i < a.length(); i++) {
    if (i < a.length() - 1 && m.find(a.substr(i, 2)) != m.end()) {
      a_val += m[a.substr(i, 2)];
      i++;
    } else {
      a_val += m[a.substr(i, 1)];
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (i < b.length() - 1 && m.find(b.substr(i, 2)) != m.end()) {
      b_val += m[b.substr(i, 2)];
      i++;
    } else {
      a_val += m[b.substr(i, 1)];
    }
  }

  cout << a_val + b_val << '\n';
  cout << to_roma(a_val + b_val);

  return 0;
}