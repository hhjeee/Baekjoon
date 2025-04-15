#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct lecture {
  int pay, day;
};
struct compare {
  bool operator()(lecture a, lecture b) {
    if (a.pay == b.pay)
      return a.day > b.day;
    return a.pay < b.pay;
  }
};

vector<int> days;
void find_day(int pay, int day) {
  if (!days[day])
    days[day] = pay;
  else {
    int tmp = day - 1;
    while (tmp > 0) {
      if (!days[tmp]) {
        days[tmp] = pay;
        break;
      }
      tmp--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<lecture, vector<lecture>, compare> pq;
  int max_day = 0;
  while (n--) {
    int p, d;
    cin >> p >> d;
    pq.push({p, d});
    max_day = max(max_day, d);
  }

  days.resize(max_day+1, 0);

  while (!pq.empty()) {
    find_day(pq.top().pay, pq.top().day);
    pq.pop();
  }

  int sum = 0;
  for (int i = 1; i <= max_day; i++) {
    sum += days[i];
  }

  cout << sum;

  return 0;
}