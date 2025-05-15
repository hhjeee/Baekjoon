#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    string w;
    int k;
    cin >> w >> k;

    unordered_map<char, int> um;

    int left = 0, right = k - 1;
    int min_val = w.length() + 1;

    for (int i = left; i <= right; i++) {
      um[w[i]] += 1;
    }
    while (right < w.length() && left <= right) {
      if (um[w[right]] == k || um[w[left]] == k) {
        min_val = min(min_val, right - left + 1);
        um[w[left]]--;
        left++;
      } else {
        right++;
        um[w[right]]++;
      }
    }

    um.clear();
    right = k - 1;
    int max_val = 0;
    for (int i = 0; i <= right; i++) {
      um[w[i]] += 1;
    }
    while (right < w.length()) {
      if (um[w[right]] >= k) {
        int tmp = 1;
        for (int i = right; i >= 0; i--) {
          if (w[i] == w[right]) {
            if (tmp == k) {
              max_val = max(max_val, right - i + 1);
              break;
            } else
              tmp++;
          }
        }
      }
      right++;
      um[w[right]]++;
    }

    if (min_val == w.length() + 1 && max_val == 0)
      cout << -1 << '\n';
    else
      cout << min_val << ' ' << max_val << '\n';
  }

  return 0;
}