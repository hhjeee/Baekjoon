#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

int bfs(int start, vector<int> exception) {
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    int count = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : adjList[cur]){
            if(visited[next]) continue;
            if(!(cur == exception[0] && next == exception[1]) && 
              !(cur == exception[1] && next == exception[0])) {
                q.push(next);
                visited[next] = true;
                count++;
            }
        }
    }
    
    return count;
}
int solution(int n, vector<vector<int>> wires) {
    adjList.resize(n+1);
    for(auto w : wires){
        adjList[w[0]].push_back(w[1]);
        adjList[w[1]].push_back(w[0]);
    }
    
    int answer = 101;
    for(int i=0; i<wires.size(); i++){
        visited.clear();
        visited.resize(n+1, false);
        int gap = 0;
        
        for(int j=1; j<=n; j++){
            if(!visited[j]) {
                gap = abs(bfs(j, wires[i]) - gap);
            }
        }
        
        answer = min(gap, answer);
    }
    
    return answer;
}