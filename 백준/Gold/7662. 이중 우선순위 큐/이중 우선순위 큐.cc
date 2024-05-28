#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, k, n;
    char c;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> k;

        priority_queue<int, vector<int>, greater<int> > min_pq;
        priority_queue<int> max_pq;
        map<int, int> counts;

        for (int j=0; j<k; j++){
            cin >> c >> n;
            if (c == 'I') { max_pq.push(n); min_pq.push(n); counts[n]++;}
            else if (c == 'D' && n == 1) {
                //최대값 제거
                while (!max_pq.empty() && counts[max_pq.top()]==0) {
                    max_pq.pop();
                }
                if (!max_pq.empty()){
                counts[max_pq.top()]--;
                max_pq.pop();}
            }
            else if (c == 'D' && n == -1) {
                // 최솟값 제거
                while (!min_pq.empty() && counts[min_pq.top()]==0) {
                    min_pq.pop();
                }
                if(!min_pq.empty()){
                counts[min_pq.top()]--;
                min_pq.pop();}
            }
        }

        while (!max_pq.empty() && counts[max_pq.top()] == 0) {
            max_pq.pop();
        }
        while (!min_pq.empty() && counts[min_pq.top()] == 0) {
            min_pq.pop();
        }

        if (max_pq.empty() || min_pq.empty()) cout << "EMPTY" << '\n';
        else cout << max_pq.top() << ' ' << min_pq.top() << '\n';

    }
    return 0;
}