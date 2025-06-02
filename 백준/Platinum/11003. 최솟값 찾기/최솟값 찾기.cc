#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, l;
    cin >> n >> l;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    deque<int> dq;
    
    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.front() < i-l+1) {
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] > nums[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        cout << nums[dq.front()] << ' ';
    }
    return 0;
}