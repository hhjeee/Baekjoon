#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int m;
  cin >> m;

  vector<int> nums(21, 0);
  cin.ignore();
  while (m--) {
    string s;
    getline(cin, s);

    if (s.find(' ') != string::npos) {
      string c = s.substr(0, s.find(' '));
      int n = stoi(s.substr(s.find(' ')));

      if (c == "add") {
        nums[n] = n;
      } else if (c == "remove") {
        nums[n] = 0;
      } else if (c == "check") {
        cout << (nums[n] == n ? 1 : 0) << '\n';
      } else if (c == "toggle") {
        if (nums[n] == n)
          nums[n] = 0;
        else
          nums[n] = n;
      }
    } else {
      if (s == "all") {
        for (int i = 1; i <= 20; i++) {
          nums[i] = i;
        }
      } else if (s == "empty") {
        fill(nums.begin(), nums.end(), 0);
      }
    }
  }

  return 0;
}