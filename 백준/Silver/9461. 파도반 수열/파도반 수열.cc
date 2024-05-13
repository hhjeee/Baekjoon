#include <iostream>
using namespace std;

long long int wave(int n);
int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        cout << wave(n) << '\n';
    }

    return 0;
}

long long int wave(int n) {
    long long int arr[102];

    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = arr[5] = 2;

    for(int i=6; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-5];
    }

    return arr[n];
}
