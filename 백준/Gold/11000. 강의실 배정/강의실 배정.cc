#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<pii, vector<pii>, greater<pii> > lecture;
  for (int i = 0; i < n; i++) {
    int s, n;
    cin >> s >> n;
    lecture.push(make_pair(s, n));
  }

  priority_queue<int, vector<int>, greater<int> > count;
  count.push(lecture.top().second);
  lecture.pop();

  while(!lecture.empty()) {
    pii top = lecture.top();

    if(count.top() > top.first) count.push(top.second);
    else {
        count.pop();
        count.push(top.second);
    }

    lecture.pop();
  }

  cout << count.size();

  return 0;
}