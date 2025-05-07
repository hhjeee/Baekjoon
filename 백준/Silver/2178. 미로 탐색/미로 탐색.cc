#include<stdio.h>
int arr[101][101] = {0, };
int queue[10001][2];
int n=0, m=0;

int bfs();

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]); 
        }
    }

    int result = bfs();
    printf("%d", result);

    return 0;
}

int bfs() {
    int x=1, y=1;
    int sp=0, bp=0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    queue[sp][0] = 1;
    queue[sp][1] = 1;
    bp++;

    while(sp < bp) {
        x = queue[sp][0];
        y = queue[sp++][1];
        
        for (int i = 0; i < 4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];

            if((tx > 1 || tx < m || ty > 1 || ty < n) && arr[tx][ty] == 1){
                //이전 칸에서 한칸 더한 수 = 거리
                arr[tx][ty] = arr[x][y] + 1; 

                queue[bp][0] = tx;
                queue[bp][1] = ty;
                bp++;
            }
        }
    }
    return arr[n][m];
}