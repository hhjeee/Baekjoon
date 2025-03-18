#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> meeting;

int find_idx(int idx, int time) {
  for (int i = idx-1; i >=0; i--) {
    if (meeting[i].second <= time) {
      return i;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;

    meeting.push_back(make_pair(start, end));
  }

  sort(meeting.begin(), meeting.end());

  int count = 0;
  int idx = n-1;
  int time = meeting[n-1].first;
  while (idx >= 0) {
    count++;
          
    idx = find_idx(idx, time);
    time = meeting[idx].first;
  }
  
  cout << count;

  return 0;
}
