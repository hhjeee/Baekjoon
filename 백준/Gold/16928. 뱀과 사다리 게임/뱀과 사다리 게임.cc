#include <iostream>
#include <queue>
using namespace std;
int toGo[101] =  {0, };
int board[101] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; // 사다리, 뱀
    cin >> n >> m;

    for(int i=0; i<n+m; i++) {
        int x, y;
        cin >> x >> y;
        toGo[x] = y;
    }

    queue<int> q;
    q.push(1);
    board[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=1; i<=6; i++) {
            int next = cur + i;
            if(next > 100) break;
            if(toGo[next]) next = toGo[next]; //사다리나 뱀이라면 이동
            if(!board[next]) {  //처음 가는 곳일때 횟수 갱신
                board[next] = board[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << board[100]-1;

    return 0;
}