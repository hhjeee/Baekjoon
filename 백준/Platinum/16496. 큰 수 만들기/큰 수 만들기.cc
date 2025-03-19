#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(string a, string b) { return a + b > b + a; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> numbers;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    numbers.push_back(to_string(num));
  }

  sort(numbers.begin(), numbers.end(), compare);

  if (numbers[0] == "0")
    cout << "0";
  else {
    string result = "";
    for (string num : numbers) {
      result += num;
    }

    cout << result;
  }

  return 0;
}