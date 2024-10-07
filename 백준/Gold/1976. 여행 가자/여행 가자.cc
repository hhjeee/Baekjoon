#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int findPath(int n, int from, int to, vector<vector<int> > &connection) {
  stack<int> stack;
  vector<int> visited(n, 0);
  stack.push(from);

  while (!stack.empty()) {
    int top = stack.top();
    stack.pop();

    if(top == to) return true;
    
    if(visited[top] == 0) {
        visited[top] = 1;

        for (int i = 0; i < n; i++) {
            if (connection[top][i] != 0 && visited[i] == 0)
                stack.push(i);
        }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int> > connection(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> connection[i][j];
    }
  }
  vector<int> trip(m);
  for (int i = 0; i < m; i++) {
    cin >> trip[i];
    trip[i]--; //index 0부터 이므로
  }

  for (int i = 0; i < m - 1; i++) {
    // trip[i] trip[i+1]이 연결되어 있는지 확인
    // 아니면
    if (!findPath(n, trip[i], trip[i + 1], connection)) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}