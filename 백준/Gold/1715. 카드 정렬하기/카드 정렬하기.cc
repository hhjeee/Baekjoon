#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    int result = 0;
    while(!pq.empty()) {
        int card1 = pq.top();
        pq.pop();
        if (pq.empty()) break;
        int card2 = pq.top();
        pq.pop();

        result += (card1 + card2);
        pq.push(card1 + card2);
    }

    cout << result;
    return 0;
}
