#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
           if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << "0" << '\n';
            }
        } else {
            pq.push(x);
        } 
    }
    return 0;
}
