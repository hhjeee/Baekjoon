#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

bool compare(pair<char, string> a, pair<char, string> b) {
  if (a.second.length() == b.second.length())
    return a.second > b.second;
  else
    return a.second.length() > b.second.length();
}

int charToInt(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return c - 'A' + 10;
}
char intToChar(int n) {
  if (n < 10)
    return n + '0';
  else
    return n - 10 + 'A';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // 0~9, A~Z(10~35)
  int n, k;
  cin >> n;

  vector<string> str(n);
  vector<vector<int>> w(36, vector<int>(50, 0));
  for (int i = 0; i < n; i++) {
    cin >> str[i];
    for (int j = 0; j < str[i].length(); j++) {
      char c = charToInt(str[i][j]);
      w[c][50 - (str[i].length() - j)]++;
    }
  }

  cin >> k;

  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 50; j++) {
      w[i][j] *= (35 - i);
    }
  }

  map<char, string> m;
  for (int i = 0; i < 35; i++) {
    string result = "";
    long long int carry = 0;
    for (int j = 49; j >= 0 || carry > 0; j--) {
      if (j >= 0)
        carry += w[i][j];
      int tmp = carry % 36;
      carry = carry / 36;
      result = intToChar(tmp) + result;
    }
    int idx = 0;
    while (idx < result.size() - 1 && result[idx] == '0') {
      idx++;
    }
    result = result.substr(idx);
    m[intToChar(i)] = result;
  }

  // map을 기반으로 벡터 생성 -> 정렬
  vector<pair<char, string>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), compare);

  // 벡터에서 높은 가중치의 k개만큼을 set으로 구성
  unordered_set<char> s;
  for (int i = 0; i < v.size() && i < k; i++) {
    s.insert(v[i].first);
  }

  // 가장 낮은 수 k개를 z로 바꾸기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < str[i].length(); j++) {
      if (s.find(str[i][j]) != s.end())
        str[i][j] = 'Z';
    }
  }

  // 각 문자열 뒤집기 + 최대 자리수 계산
  int max_len = 0;
  for (int i = 0; i < n; i++) {
    reverse(str[i].begin(), str[i].end());
    max_len = max(max_len, (int)str[i].length());
  }

  string result = "";
  long long int carry = 0;
  for (int i = 0; i < max_len || carry > 0; i++) {
    long long int sum = carry;
    for (int j = 0; j < n; j++) {
      if (str[j].length() > i) {
        sum += charToInt(str[j][i]);
      }
    }
    int tmp = sum % 36;
    carry = sum / 36;
    result = intToChar(tmp) + result;
  }

  // 앞부분 0 제거
  int idx = 0;
  while (idx < result.size() - 1 && result[idx] == '0')
    idx++;
  result = result.substr(idx);

  cout << result;

  return 0;
}
