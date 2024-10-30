#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

vi switch_on(vi cur, int idx) {
  if (idx == 0) {
    cur[idx + 1] = !cur[idx + 1];
  } else if (idx == cur.size() - 1) {
    cur[idx - 1] = !cur[idx - 1];
  } else {
    cur[idx - 1] = !cur[idx - 1];
    cur[idx + 1] = !cur[idx + 1];
  }
  cur[idx] = !cur[idx];

  return cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vi cur(n);
  for (int i = 0; i < n; i++) {
    char tmp;
    cin >> tmp;
    cur[i] = (int)(tmp - '0');
  }
  vi want(n);
  for (int i = 0; i < n; i++) {
    char tmp;
    cin >> tmp;
    want[i] = (int)(tmp - '0');
  }

  if (cur[0] == want[0]) {
    // 둘다 누름
    vi cur1 = cur;
    cur1 = switch_on(cur1, 0);
    cur1 = switch_on(cur1, 1);
    int count1 = 2;
    for (int i = 1; i < n - 1; i++) {
      if (cur1[i] != want[i]) {
        cur1 = switch_on(cur1, i + 1);
        count1++;
      }
    }
    if (cur1[n - 1] != want[n - 1])
      count1 = INT_MAX;

    // 둘다 안누름
    vi cur2 = cur;
    int count2 = 0;
    for (int i = 1; i < n - 1; i++) {
      if (cur2[i] != want[i]) {
        cur2 = switch_on(cur2, i + 1);
        count2++;
      }
    }
    if (cur2[n - 1] != want[n - 1])
      count2 = INT_MAX;

    int min_count = min(count1, count2);
    cout << ((min_count == INT_MAX) ? -1 : min_count);
  } else {
    // 0번만
    vi cur3 = cur;
    cur3 = switch_on(cur3, 0);
    int count3 = 1;
    for (int i = 1; i < n - 1; i++) {
      if (cur3[i] != want[i]) {
        cur3 = switch_on(cur3, i + 1);
        count3++;
      }
    }
    if (cur3[n - 1] != want[n - 1])
      count3 = INT_MAX;

    // 1번만
    vi cur4 = cur;
    cur4 = switch_on(cur4, 1);
    int count4 = 1;
    for (int i = 1; i < n - 1; i++) {
      if (cur4[i] != want[i]) {
        cur4 = switch_on(cur4, i + 1);
        count4++;
      }
    }
    if (cur4[n - 1] != want[n - 1])
      count4 = INT_MAX;

    int min_count = min(count3, count4);
    cout << ((min_count == INT_MAX) ? -1 : min_count);
  }

  return 0;
}