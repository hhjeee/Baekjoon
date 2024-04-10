#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 절대값 최소힙
int main(void){
    // 시간초과 해결
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    //처음 값을 기준으로 동작
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; 

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
           if(!pq.empty()){
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else{
                cout << "0" << '\n';
            }
        } else {
            pq.push({abs(x), x});
        } 
    }
    return 0;
}
