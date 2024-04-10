#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;

        if(i==0) max_pq.push(x);
        else {
            if(x <= max_pq.top()) max_pq.push(x);
            else min_pq.push(x);
        }

        if((int)max_pq.size() - (int)min_pq.size() > 1) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        } else if(min_pq.size() > max_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }

        cout << max_pq.top() << '\n';   
    }

    return 0;
}