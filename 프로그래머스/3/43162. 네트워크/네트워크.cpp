#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<int> visited(n, 0);
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(!visited[i]) {
            count++;
            
            queue<int> q;
            q.push(i);
            visited[i]=1;
            
            while(!q.empty()) {
                int top = q.front();
                q.pop();
                
                for(int j=0; j<n; j++){
                    if(computers[top][j] == 1 && !visited[j]){
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    
    return count;
}