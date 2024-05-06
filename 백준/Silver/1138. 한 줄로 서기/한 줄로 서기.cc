#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int memoryList[11];
    for (int i=0; i<n; i++) {
        cin >> memoryList[i];
    }

    int standingList[11] = {0, };
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<n; j++) {
            if (standingList[j] == 0) {
                count++;
            }
            if (count > memoryList[i]) {
                standingList[j] = i+1;
                break;
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << standingList[i] << ' ';
    }

    return 0;
}