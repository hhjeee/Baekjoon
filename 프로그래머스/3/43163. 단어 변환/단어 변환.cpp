#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

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

int dfs(int cur, int depth, string target, vector<string> words){
    visited[cur] = true;
    if(words[cur].compare(target) == 0) return depth;
    
    for(int next : adjList[cur]) {
        if(!visited[next]) {
            int res = dfs(next, depth + 1, target, words);
            if (res != -1) return res;
        }
    }
    
    return -1;
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
    visited.resize(n, false);
    adjList.resize(n);
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(check_one_differ(new_words[i], new_words[j])){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    int answer = dfs(0, 0, target, new_words);
    if(answer == -1) return 0;
    
    return answer;
}