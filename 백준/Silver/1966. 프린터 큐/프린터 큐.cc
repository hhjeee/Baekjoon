#include <iostream>
#include <queue>
using namespace std;
int arr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int n, m, order=1;
        cin >> n >> m;

        queue<pair<int, int> > q;
        priority_queue<int> pq;

        for(int j=0; j<n; j++) {
            cin >> arr[j];

            q.push(make_pair(arr[j], j));
            pq.push(arr[j]);
        }

        while(!q.empty()) {
            int value = q.front().first;
            int index = q.front().second;

            if (value >= pq.top()) {
                if(index == m) {
                    cout << order << '\n';
                    break;
                }

                order++;
                q.pop(); 
                pq.pop();
            } else {
                q.pop();
                q.push(make_pair(value, index));
            }
        }
    }

    return 0;
}