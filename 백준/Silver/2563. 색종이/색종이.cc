#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int paper[101][101] = {0, };

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        for(int j=a; j<a+10; j++) {
            for(int k=b; k<b+10; k++) {
                paper[j][k] = paper[j][k] + 1;
            }
        }
    }

    int count=0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if (paper[i][j] > 0) count++;
        }
    }

    cout << count;
    
    return 0;
}