#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long int;
using ld = long double;
ll arr[500001];
ll tmp[8001] = {0, };
vector<pair<int, int> > counts;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first; // 값이 같다면 키의 오름차순
    }
    return a.second > b.second; // 값의 내림차순
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, sum=0, res3;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
        sum += arr[i]; 
        tmp[arr[i] + 4000]++;

        counts.push_back(make_pair(arr[i] + 4000, tmp[arr[i] + 4000]));
    }

    int r = round(double(sum)/double(n));
    int res1= (r == 0) ? abs(r) : r;

    sort(arr, arr+n);
    sort(counts.begin(), counts.end(), compare);
    counts[0].second == counts[1].second ? res3 = counts[1].first - 4000 : res3 = counts[0].first - 4000;

    cout << res1 << '\n' << arr[n/2]  <<'\n' << res3 << '\n' << arr[n-1] - arr[0];

    return 0;
}