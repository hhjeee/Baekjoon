#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isSame(const string& t, const string& str, int i){
    int len = str.length();
    for(int j=0; j<len; j++){
        if(t[i-len+j] != str[j]) return false;
    }
    return true;
}

int solution(vector<string> strs, string t)
{
    int n = t.length();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(const string& str : strs){
            int len = str.length();

            if(len > i) continue;
            if(dp[i-len] == INT_MAX) continue;

            if(isSame(t, str, i)){
                dp[i] = min(dp[i], dp[i-len]+1);
            }
        }
    }

   return (dp[n] == INT_MAX) ? -1 : dp[n];
}