// 2206
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row; 
        for (int j = 0; j < m; j++) {
            map[i][j] = row[j] - '0'; 
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    // vector<vector<int> > visited(n, vector<int>(m, -1));
    // //-1(방문x), 0(안부수고 방문), 1(부수고 방문)
    // visited[0][0] = 0;
    // queue<pair<pair<int, int>, int> > q; // ((x, y), 벽 부쉈나)
    // q.push(make_pair(make_pair(0, 0), 0)); 

    // int distance = 1;
    // while (!q.empty()) {
    //   int size=q.size();
    //     for (int i = 0; i < size; i++) {
    //         int x = q.front().first.first;
    //         int y = q.front().first.second;
    //         int broke = q.front().second; 

    //         q.pop();

    //         if (x == n - 1 && y == m - 1) { // (n,m) 도착
    //             cout << distance;
    //             return 0;
    //         }

    //         for (int j = 0; j < 4; j++) {
    //             int nx = x + dx[j];
    //             int ny = y + dy[j];
    //             if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
    //                 if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
    //                     visited[nx][ny] = broke; 
    //                     q.push(make_pair(make_pair(nx, ny), broke));
    //                 }
    //                 else if (map[nx][ny] == 1 && broke == 0 && visited[nx][ny] == -1) {
    //                     visited[nx][ny] = 1; 
    //                     q.push(make_pair(make_pair(nx, ny), 1)); 
    //                 }
    //             }
    //         }
    //     }
    //     distance++; 
    // }

    vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(2, -1)));
    visited[0][0][0] = 0; 
    queue<pair<pair<int, int>, int> > q; // ((x, y), 벽 부쉈나)
    q.push(make_pair(make_pair(0, 0), 0)); 

    int distance = 1; 
    while (!q.empty()) {
        int size = q.size(); 
        for (int i = 0; i < size; i++) { 
            int x = q.front().first.first;
            int y = q.front().first.second;
            int broke = q.front().second; 
            q.pop();

            if (x == n - 1 && y == m - 1) { // (n,m) 도착
                cout << distance << '\n';
                return 0;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (map[nx][ny] == 0 && visited[nx][ny][broke] == -1) {
                        visited[nx][ny][broke] = 1; 
                        q.push(make_pair(make_pair(nx, ny), broke));
                    }
                    else if (map[nx][ny] == 1 && broke == 0 && visited[nx][ny][1] == -1) {
                        visited[nx][ny][1] = 1; 
                        q.push(make_pair(make_pair(nx, ny), 1)); 
                    }
                }
            }
        }
        distance++; 
    }

    cout << -1;
    return 0;
}
