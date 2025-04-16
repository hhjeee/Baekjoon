#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, pair<string, int>> parent;

pair<string, int> find(string a) {
  if (parent[a].first == a)
    return parent[a];
  return parent[a] = find(parent[a].first);
}
void uni_on(string a, string b) {
  pair<string, int> rootA = find(a);
  pair<string, int> rootB = find(b);

  if (rootA.first != rootB.first){
    parent[rootB.first].first = rootA.first;
    parent[rootA.first].second = rootA.second + rootB.second;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int f;
    cin >> f;
    while (f--) {
      string a, b;
      cin >> a >> b;

      if (parent.find(a) == parent.end())
        parent[a] = {a, 1}; 
      if (parent.find(b) == parent.end())
        parent[b] = {b, 1}; 

      uni_on(a, b);
      cout << find(a).second << '\n';
    }
    parent.clear();
  }

  return 0;
}