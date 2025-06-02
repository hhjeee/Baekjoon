#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int n = name.length();
    
    int answer = 0;

    for(int i=0; i<n; i++){   
        if(name[i] <= 'N') answer += (name[i] - 'A');
        else answer += ('Z' - name[i] + 1);
    }
    
    int min_ga = n - 1;
    for(int i=0; i<n; i++){
        int idx = i+1;
        while(idx < n && name[idx] == 'A') idx++;
        int rl = i + i + (n - idx);
        int lr = (n-idx) * 2 + i;
        min_ga = min(min_ga, min(rl, lr));
    }
    
    return answer + min_ga;
}