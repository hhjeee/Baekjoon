#include <iostream>
#include <cmath>
using namespace std;

void cantor(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    
    while(cin >> n){
        cantor(n);
        cout << '\n';
    }

    return 0;
}
void cantor (int n) {
    if (n == 0) cout << '-';
    else {
        cantor(n-1);
        for(int i=0; i<pow(3, n-1); i++) {
            cout << ' ';
        }
        cantor(n-1);
    }
}