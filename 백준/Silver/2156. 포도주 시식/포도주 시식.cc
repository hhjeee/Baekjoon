#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int amount[n+1];

    for(int i=0; i<n; i++) {
        cin >> amount[i];
    }

    int noEat[n+1];
    int eat[n+1];

    noEat[0] = 0;
    eat[0] = amount[0];

    noEat[1] = amount[0];
    eat[1] = amount[0] + amount[1];

    for(int i=2; i<n; i++){
        noEat[i] = max(noEat[i-1], eat[i-1]);
        eat[i] = max((noEat[i-1] + amount[i]), (noEat[i-2] + amount[i-1] + amount[i]));
    }

    cout << max(noEat[n-1], eat[n-1]);
    return 0;
}