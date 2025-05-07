#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, c;
  cin >> n >> c;

  vector<int> v(n);
  unordered_map<int, int> um;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    um[v[i]] += 1;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  vector<bool> pushed(c, false);
  for (int i = 0; i < n; i++) {
    if (!pushed[v[i]])
      pq.push({um[v[i]], i});
    pushed[v[i]] = true;
  }

  while (!pq.empty()) {
    int count = pq.top().first;
    while (count--) {
      cout << v[pq.top().second] << ' ';
    }

    pq.pop();
  }

  return 0;
}