#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> arr(n, vector<int>(m));
    int max_height = 0;
    int min_height = 256;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            max_height = max(max_height, arr[i][j]);
            min_height = min(min_height, arr[i][j]);
        }
    }

    int min_cost = INT_MAX;
    int best_height = 0;

    for (int height = 0; height <= 256; height++) {
        int add = 0, remove = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] < height) {
                    add += (height - arr[i][j]);
                } else if (arr[i][j] > height) {
                    remove += (arr[i][j] - height);
                }
            }
        }
        if (remove + b >= add) { // 체크 인벤토리
            int cost = add + 2 * remove;
            if (cost < min_cost || (cost == min_cost && height > best_height)) {
                min_cost = cost;
                best_height = height;
            }
        }
    }

    cout << min_cost << ' ' << best_height << '\n';

    return 0;
}
