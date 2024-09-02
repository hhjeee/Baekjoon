#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int arr[3] = {0};
  cin >> arr[0] >> arr[1] >> arr[2];

  int min_arr[3] = {arr[0], arr[1], arr[2]};
  int max_arr[3] = {arr[0], arr[1], arr[2]};

  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    // 최대
    int max_tmp[3] = {max_arr[0], max_arr[1], max_arr[2]};

    max_arr[0] = max(max_tmp[0], max_tmp[1]) + a;
    max_arr[1] = max(max(max_tmp[0], max_tmp[1]), max_tmp[2]) + b;
    max_arr[2] = max(max_tmp[1], max_tmp[2]) + c;

    // 최소
    int min_tmp[3] = {min_arr[0], min_arr[1], min_arr[2]};

    min_arr[0] = min(min_tmp[0], min_tmp[1]) + a;
    min_arr[1] = min(min(min_tmp[0], min_tmp[1]), min_tmp[2]) + b;
    min_arr[2] = min(min_tmp[1], min_tmp[2]) + c;
  }

  cout << max(max(max_arr[0], max_arr[1]), max_arr[2]) << ' '
       << min(min(min_arr[0], min_arr[1]), min_arr[2]);

  return 0;
}