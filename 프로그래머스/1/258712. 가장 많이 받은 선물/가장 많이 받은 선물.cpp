#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// 두 사람 사이에 더 많은 선물 준 사람 -> 선물 하나 받음
// 기록 x or 주고받은수 == -> 선물지수 큰 사람 받음 (같으면 x)
// 선물지수 = 준 선물의 수 - 받은 선물의 수 
int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size(); 
    
    vector<vector<int>> gift_count(n, vector<int>(n, 0)); // 주고받은 선물
    for(int i=0; i<gifts.size(); i++) {
        istringstream iss(gifts[i]); 
        string from, to;

        if (iss >> from >> to) {
            auto it = find(friends.begin(), friends.end(), from);
            int from_index = distance(friends.begin(), it);
            auto it2 = find(friends.begin(), friends.end(), to);
            int to_index = distance(friends.begin(), it2);
            
            gift_count[from_index][to_index]++;
        } 
    }
    
    vector<int> gift_jisu(n); //선물지수
    for(int i=0; i<n; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            count += gift_count[i][j];
        }
        gift_jisu[i] = count;
    }
    for(int i=0; i<n; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            count -= gift_count[j][i];
        }
        gift_jisu[i] += count;
    }
    
    vector<int> get_gift(n); //받게 될 선물
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j && i < j) {
                if(gift_count[i][j] > gift_count[j][i]) get_gift[i]++;
                else if(gift_count[i][j] < gift_count[j][i]) get_gift[j]++;
                else {
                    if(gift_jisu[i] > gift_jisu[j]) get_gift[i]++;
                    else if(gift_jisu[i] < gift_jisu[j]) get_gift[j]++;
                }
            }
        }
    }
    
    int max = 0;
    for(int i=0; i<n; i++) {
        if(max < get_gift[i]) max = get_gift[i];
    }

    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}