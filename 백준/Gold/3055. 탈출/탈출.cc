#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int r, c;
vector<vector<char> > map;
queue<pair<int, int> > waterQ;
queue<pair<int, int> > SQ;
vector<vector<bool> > visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int moveS() {
  int num = SQ.size();
  if(num == 0) return -1;

  for (int i = 0; i < num; i++) {
    pair<int, int> cur = SQ.front();
    SQ.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = cur.first + dx[i];
      int next_y = cur.second + dy[i];

      if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c && !visited[next_x][next_y]) {
        if(map[next_x][next_y] == '.') {
            visited[next_x][next_y] = true;
            SQ.push(make_pair(next_x, next_y));
        } else if(map[next_x][next_y] == 'D')
          return 1;
      }
    }
  }
  return 0;
}
void water() {
  int num = waterQ.size();
  for (int i = 0; i < num; i++) {
    pair<int, int> cur = waterQ.front();
    waterQ.pop();

    for (int j = 0; j < 4; j++) {
      int next_x = cur.first + dx[j];
      int next_y = cur.second + dy[j];

      if ((next_x >= 0 && next_x < r && next_y >= 0 && next_y < c) &&
          map[next_x][next_y] == '.') {
        map[next_x][next_y] = '*';
        waterQ.push(make_pair(next_x, next_y));
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c;

  map.resize(r, vector<char>(c));
  visited.resize(r, vector<bool>(c, false));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];

      if (map[i][j] == '*')
        waterQ.push(make_pair(i, j));
      if (map[i][j] == 'S')
        SQ.push(make_pair(i, j));
    }
  }

  int time = 0;
  while (1) {
    time++;

    // 물 확산
    water();

    // 고슴도치 이동
    int result = moveS();
    if(result == 1) { cout << time; break; }
    else if(result == -1) { cout << "KAKTUS"; break; }
  }

  return 0;
}