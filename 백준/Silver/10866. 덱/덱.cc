#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  cin.ignore();

  deque<int> dq;

  while (n--) {
    string s;
    getline(cin, s);

    istringstream iss(s);
    string cmd;
    iss >> cmd;

    if (cmd == "push_front") {
      int n;
      iss >> n;
      dq.push_front(n);
    } else if (cmd == "push_back") {
      int n;
      iss >> n;
      dq.push_back(n);
    } else if (cmd == "pop_front") {
      if (dq.empty())
        cout << -1 << '\n';
      else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (cmd == "pop_back") {
      if (dq.empty())
        cout << -1 << '\n';
      else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (cmd == "size") {
      cout << dq.size() << '\n';
    } else if (cmd == "empty") {
      cout << (dq.empty() ? 1 : 0) << '\n';
    } else if (cmd == "front") {
      if (dq.empty())
        cout << -1 << '\n';
      else
        cout << dq.front() << '\n';
    } else if (cmd == "back") {
      if (dq.empty())
        cout << -1 << '\n';
      else
        cout << dq.back() << '\n';
    }
  }

  return 0;
}