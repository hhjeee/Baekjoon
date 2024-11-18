#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> every_combination(vector<vector<int>> sub_dice) {
    vector<int> sum;
    sum.push_back(0); 

    for (int i = 0; i < sub_dice.size(); i++) {
        vector<int> new_sum;
        for (int j = 0; j < sum.size(); j++) {
            for (int k = 0; k < sub_dice[i].size(); k++) {
                new_sum.push_back(sum[j] + sub_dice[i][k]);
            }
        }
        sum = new_sum; 
    }

    return sum;
}
// vector<int> every_combination(vector<vector<int>> sub_dice) {
//     int n = sub_dice.size();
//     vector<int> sum;
    
//     if(n == 1) {
//         for(int i=0; i<6; i++) {
//             sum.push_back(sub_dice[0][i]);
//         }
//     } else if(n == 2) {
//         for(int i=0; i<6; i++) {
//              for(int j=0; j<6; j++) {
//                 sum.push_back(sub_dice[0][i] + sub_dice[1][j]);
//              }
//         }
//     } else if(n==3) {
//         for(int i=0; i<6; i++) {
//              for(int j=0; j<6; j++) {
//                  for(int k=0; k<6; k++) {
//                     sum.push_back(sub_dice[0][i] + sub_dice[1][j] + sub_dice[2][k]);
//                  }
//              }
//         }
//     } else if(n==4) {
//         for(int i=0; i<6; i++) {
//              for(int j=0; j<6; j++) {
//                  for(int k=0; k<6; k++) {
//                      for(int l=0; l<6; l++) {
//                     sum.push_back(sub_dice[0][i] + sub_dice[1][j] + sub_dice[2][k] + sub_dice[3][l]);
//                      }
//                  }
//              }
//         }
//     } else if(n==5) {
//         for(int i=0; i<6; i++) {
//              for(int j=0; j<6; j++) {
//                  for(int k=0; k<6; k++) {
//                      for(int l=0; l<6; l++) {
//                          for(int m=0; m<6; m++) {
//                     sum.push_back(sub_dice[0][i] + sub_dice[1][j] + sub_dice[2][k] + sub_dice[3][l] + sub_dice[4][m]);
//                          }
//                      }
//                  }
//              }
//         }
//     } 
                
//     return sum; 
// }
vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    vector<int> arr(n, 1);
    for(int i=0; i<n/2; i++) {
        arr[i] = 0;
    }
    
    int a_win_max = 0;
    vector<int> a_dice_idx_max;
    do {
        vector<vector<int>> a_dice;
        vector<vector<int>> b_dice;
        vector<int> a_dice_idx;
        
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                a_dice.push_back(dice[i]);
                a_dice_idx.push_back(i);
            } else b_dice.push_back(dice[i]);
        }
        
        vector<int> a_sum = every_combination(a_dice);
        vector<int> b_sum = every_combination(b_dice);
        int a_win = 0;
        for(int i=0; i<a_sum.size(); i++){
            for(int j=0; j<b_sum.size(); j++) {
                if(a_sum[i] > b_sum[j]) a_win++;
            }
        }
        
        if(a_win_max < a_win) {
            a_win_max = a_win;
            a_dice_idx_max = a_dice_idx;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    
    vector<int> answer;
    for(int i=0; i<n/2; i++) {
       answer.push_back(a_dice_idx_max[i] + 1);
    }
    return answer;
}