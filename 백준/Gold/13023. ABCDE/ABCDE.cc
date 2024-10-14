// 13023
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > friends;
vector<int> visited;
bool exist = false;

void dfs(int cur, int depth) {
  if (depth == 4) {
    exist = true;
    return;
  }

  visited[cur] = 1;

  for (int j = 0; j < friends[cur].size(); j++) {
    int tmp = friends[cur][j];
    if (visited[tmp] == 0) {
      dfs(tmp, depth + 1);
      if (exist)
        return;
    }
  }

  visited[cur] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  friends.resize(n);
  visited.resize(n, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    friends[a].push_back(b);
    friends[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    fill(visited.begin(), visited.end(), 0);
    dfs(i, 0);
    if (exist)
      break;
  }

  cout << exist ? 1 : 0;

  return 0;
}
