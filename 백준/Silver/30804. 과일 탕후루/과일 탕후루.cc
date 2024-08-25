#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int tang[200001] = {0};
  int count[10] = {0};

  for (int i = 0; i < n; i++) {
    cin >> tang[i];
    // count[tang[i]]++;
  }

  int max_count = 0;
  int fruits = 0;
  int start = 0;

  for (int end = 0; end < n; end++) {
    count[tang[end]]++;
    if (count[tang[end]] == 1) {
      fruits++;
    }

    while (fruits > 2) {
      count[tang[start]]--;
      if (count[tang[start]] == 0) {
        fruits--;
      }
      start++;
    }

    max_count = max(end - start + 1, max_count);
  }

  cout << max_count;

  return 0;
}