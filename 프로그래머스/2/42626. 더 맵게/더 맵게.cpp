#include <vector>
#include <queue>
#include <iostream>

using namespace std;
using ll = long long int;

int solution(vector<int> scoville, int K) {
    priority_queue<ll, vector<ll>, greater<>> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    int count = 0;
    
    while(!pq.empty()){
        if(pq.top() >= K) break;
        if(pq.size() == 1) {count = -1; break;}
        
        count++;
        
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        
        ll new_scoville = first + second * 2;
        pq.push(new_scoville);
    }
    
    return count;
}