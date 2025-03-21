#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int size = triangle.size()-1;
    
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}