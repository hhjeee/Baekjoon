#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> visited;
vector<vector<int>> adjList;

bool check_one_differ(string a, string b) {
    int count = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]) count++;
        if(count >= 2) return false;
    }
    
    if(count == 1) return true;
    else return false;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        int top = q.front();
        q.pop();
        
        for(int next : adjList[top]){
            if(!visited[next]) {
                visited[next] = visited[top]+1;
                q.push(next);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    // words 내에 target이 없는 경우
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    vector<string> new_words;
    new_words.push_back(begin);
    for(int i=0; i<words.size(); i++){
        new_words.push_back(words[i]);
    }
    
    int n = new_words.size();
    visited.resize(n, 0);
    adjList.resize(n);
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(check_one_differ(new_words[i], new_words[j])){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    bfs(0);
    
    int target_idx = find(new_words.begin(), new_words.end(), target) - new_words.begin();
    int answer = visited[target_idx]-1;
    
    return answer;
}