#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, string> memo;

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        string site;
        string password;
        cin >> site >> password;

        memo[site] = password;
       // memo.insert({site, password});
    }

    for(int i=0; i<m; i++) {
        string siteToFind;
        cin >> siteToFind;

        // auto result = memo.find(siteToFind);
        // cout << result->second << '\n';

        cout << memo[siteToFind] << '\n';
    }

    return 0;
}