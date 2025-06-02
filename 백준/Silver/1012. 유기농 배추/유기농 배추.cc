#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
vector<vector<int>> map;
vector<vector<bool>> visited;

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    visited[sx][sy] = true;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || nx>=n || ny<0 || ny>=m) continue;
            if(visited[nx][ny] || !map[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  
  while(t--){
      int k;
      cin >> m >> n >> k;
      
      map.clear();
      map.resize(n, vector<int>(m, 0));
      while(k--){
          int x, y;
          cin >> x >> y;
          map[y][x] = 1;
      }
      
      int count = 0;
      
      visited.clear();
      visited.resize(n, vector<bool>(m, false));
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(map[i][j] && !visited[i][j]) {
                  count++;
                  bfs(i, j);
              }
          }
      }
      
      cout << count << '\n';
  }

  return 0;
}