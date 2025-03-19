#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> items(k);
  for (int i = 0; i < k; i++) {
    cin >> items[i];
  }
  
  vector<int> multi;

  int count = 0;
  for (int i = 0; i < k; i++) {
    //이미 존재
    if (find(multi.begin(), multi.end(), items[i]) != multi.end())
      continue;
      
    if(multi.size() < n) {
        multi.push_back(items[i]);
        continue;
    }

    int remove = 0;
    int max_use = -1;

    //가장 나중에 사용될거 찾기
    for (int j = 0; j < multi.size(); j++) {
      int next_use = 101;

      for (int t = i; t < k; t++) {
        if (multi[j] == items[t]) {
          next_use = t;
          break;
        }
      }

      if (next_use > max_use) {
        max_use = next_use;
        remove = j;
      }
    }

    multi[remove] = items[i];
    count++;
  }

  cout << count;

  return 0;
}