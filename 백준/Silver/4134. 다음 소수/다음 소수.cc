#include <iostream>
#include <cmath>
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll i=0; i<n; i++) {
        ll t;
        cin >> t;

        while (true) {
            int isPrime = 1;
            if (t < 2) {
                isPrime = 0;
            } else {
                for (ll j = 2; j <= sqrt(t); j++) {
                    if (t % j == 0) {
                        isPrime = 0;
                        break;
                    }
                }
            }
            if (isPrime) {
                cout << t << '\n';
                break;
            }
            t++;
        }
    }

    return 0;
}