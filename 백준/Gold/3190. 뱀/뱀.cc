#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vii = vector<int>;
using pic = pair<int, char>;
using pii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<vii> board(n, vii(n, 0));
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    board[a - 1][b - 1] = -1; // 사과
  }

  int l;
  cin >> l;
  vector<pic> direction;
  for (int i = 0; i < l; i++) {
    int x;
    char c;
    cin >> x >> c;
    direction.push_back(make_pair(x, c));
  }

  queue<pii> snake;
  snake.push(make_pair(0, 0));
  int time = 0;
  int dir_idx = 0;
  int cur_dir = 1; // 0 북, 1 동, 2 남, 3 서

  while (!snake.empty()) {
    if (dir_idx < direction.size() && direction[dir_idx].first == time) {
      if (direction[dir_idx].second == 'L')
        cur_dir = (cur_dir + 3) % 4;
      else if (direction[dir_idx].second == 'D')
        cur_dir = (cur_dir + 1) % 4;
      dir_idx++;
    }

    int head_x = snake.back().second;
    int head_y = snake.back().first;
    int tail_x = snake.front().second;
    int tail_y = snake.front().first;
    int next_x = cur_dir == 1 ? head_x + 1 : cur_dir == 3 ? head_x - 1 : head_x;
    int next_y = cur_dir == 0 ? head_y - 1 : cur_dir == 2 ? head_y + 1 : head_y;

    if (next_x < 0 || next_x >= n || next_y < 0 || next_y == n)
      break;
    if (board[next_y][next_x] == 1)
      break;

    if (board[next_y][next_x] == -1) {
      snake.push(make_pair(next_y, next_x));
      board[next_y][next_x] = 1;
    } else {
      snake.push(make_pair(next_y, next_x));
      board[next_y][next_x] = 1;
      board[tail_y][tail_x] = 0;
      snake.pop();
    }
    time++;
  }

  cout << time + 1;

  return 0;
}