#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> path;
vector<vector<string>> tickets_copy;
bool finished = false;

bool compare(vector<string> a, vector<string> b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

void dfs(string cur, int depth){
    path.push_back(cur);
    
    if(depth == tickets_copy.size()){
        finished = true;
        return;
    }
    
     for (int i = 0; i < tickets_copy.size(); ++i) {
        if (tickets_copy[i][0] == cur && tickets_copy[i][2] == "false") {
            tickets_copy[i][2] = "true";
            
            dfs(tickets_copy[i][1], depth + 1);
            
            if (finished) return;  // 정답 찾았으면 끝내기
            tickets_copy[i][2] = "false";  
        }
    }

    path.pop_back(); 
}

vector<string> solution(vector<vector<string>> tickets) {
    tickets_copy = tickets;
    sort(tickets_copy.begin(), tickets_copy.end(), compare);
    
    for(vector<string>& t : tickets_copy){
        t.push_back("false");
    }
    
    dfs("ICN", 0);
    
    return path;
}