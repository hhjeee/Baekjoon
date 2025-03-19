#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> books(n);

  for (int i = 0; i < n; i++) {
    cin >> books[i];
  }

  sort(books.begin(), books.end());

  int time = 0;
  int idx_0 = lower_bound(books.begin(), books.end(), 0) - books.begin();

  for (int i = 0; i < idx_0; i += m) {
    time += abs(books[i]) * 2;
  }
  for (int i = books.size() - 1; i >= idx_0; i -= m) {
    time += books[i] * 2;
  }

  int max_pos = max(abs(books[0]), abs(books[n - 1]));
  time -= max_pos;

  cout << time;

  return 0;
}