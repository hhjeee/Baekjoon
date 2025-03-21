#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    
    return sa + sb > sb + sa;
}
string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    
    string answer = "";
    
    if(numbers[0] == 0) return "0";
    
    for(int i=0; i<numbers.size(); i++){
        answer += to_string(numbers[i]);
    }

    return answer;
}