#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), next(n);
    vector<bool> is_deleted(n, false);
    stack<int> deleted;

    // 초기 연결 리스트 세팅
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    int cur = k;

    for (const string& c : cmd) {
        if (c[0] == 'U') {
            int x = stoi(c.substr(2));
            while (x--) cur = prev[cur];
        } else if (c[0] == 'D') {
            int x = stoi(c.substr(2));
            while (x--) cur = next[cur];
        } else if (c[0] == 'C') {
            deleted.push(cur);
            is_deleted[cur] = true;

            // 연결 끊기
            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != -1) prev[next[cur]] = prev[cur];

            // 커서 이동
            if (next[cur] != -1) cur = next[cur];
            else cur = prev[cur];
        } else if (c[0] == 'Z') {
            int rec = deleted.top(); deleted.pop();
            is_deleted[rec] = false;

            if (prev[rec] != -1) next[prev[rec]] = rec;
            if (next[rec] != -1) prev[next[rec]] = rec;
        }
    }

    string answer(n, 'O');
    for (int i = 0; i < n; i++) {
        if (is_deleted[i]) answer[i] = 'X';
    }

    return answer;
}