#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int x, k;
  cin >> x >> k;

  long long int y = 0;
  long long int k_idx = 0;

  for(int i=0; i<65; i++){
    // x의 i번째 비트가 1 -> continue
    if ((x & (1ll << i))) continue;
    
    // k의 k_idx번째 비트가 1인지 확인
    if (k & (1ll << k_idx))
        y |= (1ll << i);
        
    k_idx++;
  }

    cout << y;

    return 0;
  }
