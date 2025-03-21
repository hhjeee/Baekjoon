#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> v;
    for(int i=0; i<dungeons.size(); i++){
        v.push_back(i);
    }
    
    int max_dungeons = 0;
    
    do {
        int count = 0;
        int inner_k = k;
        
        for(int i=0; i<v.size(); i++){
            int idx = v[i];
            
            if(inner_k >= dungeons[idx][0]) {
                inner_k -= dungeons[idx][1];
                count++;
            }
        }
        
        max_dungeons = max(max_dungeons, count);
    } while(next_permutation(v.begin(), v.end()));
    
    return max_dungeons;
}