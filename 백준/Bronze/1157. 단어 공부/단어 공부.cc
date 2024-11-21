#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string input;
  cin >> input;

  vector<int> alphabet(26, 0);
  for (int i = 0; i < input.length(); i++) {
    if (input[i] >= 97 && input[i] <= 122) {
      input[i] = input[i] - 32;
    }
    alphabet[input[i] - 65]++;
  }

  int max = 0;
  char max_char;
  for (int i = 0; i < 26; i++) {
    if (max < alphabet[i]) {
      max = alphabet[i];
      max_char = i + 65;
    }
  }

  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] == max)
      count++;
  }

  if (count > 1)
    cout << "?";
  else
    cout << max_char;

  return 0;
}