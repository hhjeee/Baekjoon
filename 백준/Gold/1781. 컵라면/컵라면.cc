#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info {
  int deadline, reward;
};
struct compare {
  bool operator()(info &a, info &b) {
    // reward 큰 거부터 정렬, 같으면 deadline 짧은 것 우선
    if (a.reward == b.reward) {
      return a.deadline > b.deadline;
    }
    return a.reward < b.reward;
  }
};

vector<int> parents;
int find(int a) {
  if (parents[a] == a)
    return a;
  return parents[a] = find(parents[a]);
}
void uni_on(int a, int b) { parents[a] = b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<info, vector<info>, compare> pq;
  int max_deadline = 0;
  while (n--) {
    int d, r;
    cin >> d >> r;
    pq.push({d, r});
    max_deadline = max(max_deadline, d);
  }

  parents.resize(max_deadline + 1, 0);
  for (int i = 1; i <= max_deadline; i++)
    parents[i] = i;

  int sum = 0;
  while (!pq.empty()) {
    int d = find(pq.top().deadline);
    int r = pq.top().reward;
    pq.pop();

    if (d == 0)
      continue;

    sum += r;
    uni_on(d, d - 1);
  }

  cout << sum;

  return 0;
}