#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int sum = brown + yellow;
    int width, height;
    
    for(width=3; width<brown/2; width++){
        height = sum / width;
        
        if(width >= height) {
            if(2*width + 2*height == brown + 4) break; 
        }
    }
    
    return {width, height};
}