#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long int> count_sum(vector<long long int> sum, vector<int> v,
                                int len) {
  for (int i = 0; i < len; i++) {
    int tmp = 0;
    for (int j = i; j < len; j++) {
      tmp += v[j];
      sum.push_back(tmp);
    }
  }

  return sum;
}
int main() {
  int t, n, m;
  cin >> t >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<long long int> sum_a;
  sum_a = count_sum(sum_a, a, n);

  cin >> m;

  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  vector<long long int> sum_b;
  sum_b = count_sum(sum_b, b, m);

  sort(sum_a.begin(), sum_a.end());
  sort(sum_b.begin(), sum_b.end());

  int a_pointer = 0;
  long long int count = 0;
  while (a_pointer < sum_a.size()) {
    int cur_a = sum_a[a_pointer];
    long long int cur_count_a = upper_bound(sum_a.begin(), sum_a.end(), cur_a) -
                                lower_bound(sum_a.begin(), sum_a.end(), cur_a);

    long long int cur_count_b =
        upper_bound(sum_b.begin(), sum_b.end(), t - cur_a) -
        lower_bound(sum_b.begin(), sum_b.end(), t - cur_a);

    if (cur_count_b > 0) {
      count += cur_count_a * cur_count_b;
    }

    a_pointer += cur_count_a;
  }

  cout << count;

  return 0;
}