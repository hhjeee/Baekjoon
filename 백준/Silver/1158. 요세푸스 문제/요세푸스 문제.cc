#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  list<int> l;
  for (int i = 1; i <= n; i++)
    l.push_back(i);

  cout << "<";
  auto iter = l.begin();

  while (!l.empty()) {
    for (int i = 0; i < k - 1; i++) {
      iter++;
      if (iter == l.end())
        iter = l.begin();
    }

    cout << *iter;
    iter = l.erase(iter);

    if (iter == l.end())
      iter = l.begin();
    if (!l.empty())
      cout << ", ";
  }

  cout << ">";

  return 0;
}