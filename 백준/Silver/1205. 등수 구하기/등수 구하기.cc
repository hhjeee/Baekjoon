#include <iostream>
using namespace std;

int main() {
    int n, score, p;
    cin >> n >> score >> p;

    int rankingList[51];
    if (n > 0) {
        for (int i=0; i<n; i++) {
            cin >> rankingList[i];
        } 

        int i, count = 0;
        for (i=0; i<n; i++) {
            if (score > rankingList[i]) { 
                break;
            } else if (score == rankingList[i]) {
                count++;
            }
        }
        if (i != p) cout << i-count+1;
        else if (i == p) cout << -1;

    } else {
        cout << 1;
    }

    return 0;
}