#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string str, e;
  cin >> str >> e;

  int e_len = e.length();
  string result;

  for (char c : str) {
    result.push_back(c);

    if (c == e[e_len - 1] && result.size() >= e_len) {
      // c가 폭발문자열의 마지막문자랑 같으면

      bool is_e = true;
      for (int i = 0; i < e_len; ++i) {
        if (result[result.size() - e_len + i] != e[i]) {
          is_e = false;
          break;
        }
      }

      if (is_e) {
        for (int i = 0; i < e_len; ++i)
          result.pop_back();
      }
    }
  }

  if (result == "")
    cout << "FRULA";
  else
    cout << result;

  return 0;
}