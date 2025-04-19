#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<long long int> dist(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> dist[i]; // dist[0]은 0->1 거리
  }
  vector<long long int> price(n);
  for (int i = 0; i < n; i++) {
    cin >> price[i];
  }

  long long int cur = 0;
  long long int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    if (cur < dist[i]) {
      cur += dist[i];
      sum += dist[i] * price[i];
    }
    if (price[i] < price[i + 1]) {
      cur += dist[i + 1];
      sum += dist[i + 1] * price[i];
    }
    
    cur -= dist[i];
  }

  cout << sum;

  return 0;
}