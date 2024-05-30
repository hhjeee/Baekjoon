#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    set<string> stringArr; // 중복허용x

    for (int i=0; i<s.length(); i++) {
        for (int j=i; j<s.length(); j++){
            //s.substr(i, j); i부터 길이 j만큼 문자열 자르기
            stringArr.insert( s.substr(i, j-i+1));
        }
    }

    cout << stringArr.size();
    return 0;
}