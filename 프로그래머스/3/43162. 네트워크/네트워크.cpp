#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parent;

void init(int n) {
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
}
int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void uni_on(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    
    if(aRoot != bRoot) parent[bRoot] = aRoot;
}

int solution(int n, vector<vector<int>> computers) {
    parent.resize(n, 0);
    init(n);
    
   for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++){
           if(computers[i][j] == 1) uni_on(i, j);
       }
   }
    
    vector<int> result;
    for(int i=0; i<n; i++){
        if(find(result.begin(), result.end(), find(i)) == result.end())                    result.push_back(parent[i]);
    }
    
    return result.size();
}