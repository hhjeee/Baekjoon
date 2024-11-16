#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vii = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vii> capacity(n, vii(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> capacity[i][j];
    }
  }

  vector<int> person;
  for (int i = 0; i < n / 2; i++) {
    person.push_back(0);
    person.push_back(1);
  }

  int min = 999999;
  do {
    vector<int> start;
    vector<int> link;

    for (int i = 0; i < n; i++) {
      if (person[i] == 0)
        start.push_back(i);
      else
        link.push_back(i);
    }

    int start_capacity = 0;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        if (i < j) {
          start_capacity += capacity[start[i]][start[j]];
          start_capacity += capacity[start[j]][start[i]];
        }
      }
    }

    int link_capacity = 0;
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        if (i < j) {
          link_capacity += capacity[link[i]][link[j]];
          link_capacity += capacity[link[j]][link[i]];
        }
      }
    }

    if (min > abs(start_capacity - link_capacity))
      min = abs(start_capacity - link_capacity);

  } while (next_permutation(person.begin(), person.end()));

  cout << min;

  return 0;
}