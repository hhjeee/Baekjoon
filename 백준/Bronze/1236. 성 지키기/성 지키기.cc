#include <iostream>
#include <vector>
using namespace std;
using vc = vector<char>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vc> castle(n, vc(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> castle[i][j];
    }
  }

  vector<int> row(n, 0);
  vector<int> col(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (castle[i][j] == 'X')
        break;
      if (j == m - 1)
        row[i] = 1;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (castle[j][i] == 'X')
        break;
      if (j == n - 1)
        col[i] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (row[i] == 1 && col[j] == 1 && castle[i][j] == '.') {
        count++;
        row[i] = 0;
        col[j] = 0;
        castle[i][j] = 'X';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (row[i] == 1)
      count++;
  }
  for (int i = 0; i < m; i++) {
    if (col[i] == 1)
      count++;
  }

  cout << count;

  return 0;
}