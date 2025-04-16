#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> students;
vector<bool> visited;
vector<bool> done;

int team;

void dfs(int cur) {
  visited[cur] = true;

  int next = students[cur];
  if (!visited[next]) {
    dfs(next);
  } else if (!done[next]) {
    for (int i = next; i != cur; i = students[i]) {
      team++;
    }
    team++;
  }

  done[cur] = true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    students.clear();
    visited.clear();
    done.clear();
    students.resize(n + 1, 0);
    visited.resize(n + 1, false);
    done.resize(n + 1, false);
    team = 0;

    for (int i = 1; i <= n; i++) {
      cin >> students[i];
    }

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }

    cout << n - team << '\n';
  }

  return 0;
}