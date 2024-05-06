#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[11];
    int sum[11];
    int maxI = 0;

    for(int i=0; i<n; i++) {
        cin >> arr[i]; 
        maxI = max(maxI, arr[i]);
    }

    sum[0] = 1;
    sum[1] = 2;
    sum[2] = 4;

    for(int i=3; i<maxI; i++) {
        sum[i] = sum[i-1] + sum[i-2] + sum[i-3];
    }

    for(int i=0; i<n; i++) {
        cout << sum[arr[i]-1] << '\n';    
    }

 return 0;
}