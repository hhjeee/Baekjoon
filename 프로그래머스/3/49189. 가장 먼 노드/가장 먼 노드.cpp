#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <map>

using namespace std;

vector<int> dist;
vector<vector<int>> adjList;

void dijkstra(int start) {
    dist[start] = 0;
    queue<int> q;
    
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : adjList[cur]){
            if(dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    dist.resize(n+1, INT_MAX);
    adjList.resize(n+1);
    
    for(int i=0; i<edge.size(); i++){
        vector<int> cur = edge[i];
        
        adjList[cur[0]].push_back(cur[1]);
        adjList[cur[1]].push_back(cur[0]);
    }
    
    dijkstra(1);
    
    map<int, int> m;
    int max_val = 0;
    for(int i=1; i<=n; i++) {
        m[dist[i]]++;
        max_val = max(max_val, dist[i]);
    }
    
    return m[max_val];
}