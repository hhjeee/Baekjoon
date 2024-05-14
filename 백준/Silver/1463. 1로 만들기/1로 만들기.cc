#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    int visited[1000001] = {0,};

    q.push(n);
    visited[n]=1;

    while (visited[1] == 0) {
        int tmp = q.front();

        if (tmp%3 == 0 && visited[tmp/3] == 0) {
            q.push(tmp/3);
            visited[tmp/3] = visited[tmp]+1;
        }

        if (tmp%2 == 0 && visited[tmp/2] == 0) {
            q.push(tmp/2);
            visited[tmp/2] = visited[tmp]+1;
        }

        if (tmp-1 >= 0 && visited[tmp-1] == 0) {
            q.push(tmp-1);
            visited[tmp-1] = visited[tmp]+1;
        }

        q.pop();
    }

    cout << visited[1]-1;
    return 0;
}