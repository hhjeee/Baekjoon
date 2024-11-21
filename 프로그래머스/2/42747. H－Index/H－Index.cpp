#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int hindex=0;
    for(int i=0; i<citations.size(); i++) {
        if(citations[i] >= citations.size()-i){
            hindex = citations.size()-i;
            break;
        }
    }
    
    return hindex;
}