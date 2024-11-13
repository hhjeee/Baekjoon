#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cash;
  cin >> cash;

  // 2021년 1월 1일부터 2021년 1월 14일까지의 MachineDuck 주가
  vector<int> stream(14);
  for (int i = 0; i < 14; i++) {
    cin >> stream[i];
  }

  // 준현
  vector<int> jun_cash(15, 0); // 현금
  jun_cash[0] = cash;
  int jun_count = 0; // 주식수
  for (int i = 0; i < 14; i++) {
    if (jun_cash[i] >= stream[i]) {
      jun_count += jun_cash[i] / stream[i];
      jun_cash[i + 1] = jun_cash[i] - (jun_cash[i] / stream[i]) * stream[i];
    } else {
      jun_cash[i + 1] = jun_cash[i];
    }
  }

  int jun_final = jun_cash[14] + stream[13] * jun_count;

  // 성민
  vector<int> sung_cash(15, 0); // 현금
  sung_cash[3] = cash;
  int sung_count = 0; // 주식수
  for (int i = 3; i < 14; i++) {
    if (stream[i - 3] < stream[i - 2] && stream[i - 2] < stream[i - 1] &&
        stream[i - 1] < stream[i]) {
      // 3일 상승 -> 전량 매도
      sung_cash[i + 1] = sung_cash[i] + sung_count * stream[i];
      sung_count = 0;
    } else if (stream[i - 3] > stream[i - 2] && stream[i - 2] > stream[i - 1] &&
               stream[i - 1] > stream[i]) {
      // 3일 상승 -> 전량 매수
      if (sung_cash[i] >= stream[i]) {
        sung_count += sung_cash[i] / stream[i];
        sung_cash[i + 1] =
            sung_cash[i] - (sung_cash[i] / stream[i]) * stream[i];
      } else {
        sung_cash[i + 1] = sung_cash[i];
      }
    } else {
      sung_cash[i + 1] = sung_cash[i];
    }
  }

  int sung_final = sung_cash[14] + stream[13] * sung_count;

  if (jun_final == sung_final)
    cout << "SAMESAME";
  else if (jun_final > sung_final)
    cout << "BNP";
  else
    cout << "TIMING";

  return 0;
}