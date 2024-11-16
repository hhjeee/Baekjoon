#include <iostream>
#include <vector>

using namespace std;
using vii = vector<int>;
using pii = pair<int, int>;

vii rotate(vii circle, int direction) {
  vii circle_tmp(8);

  if (direction == 1) {
    circle_tmp[0] = circle[7];
    for (int i = 1; i < 8; i++) {
      circle_tmp[i] = circle[i - 1];
    }
  } else {
    circle_tmp[7] = circle[0];
    for (int i = 0; i < 7; i++) {
      circle_tmp[i] = circle[i + 1];
    }
  }

  return circle_tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  vector<vii> circle(4, vii(8, 0));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      char tmp;
      cin >> tmp;
      circle[i][j] = tmp - '0';
    }
  }

  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int num, direction;
    cin >> num >> direction;

    vector<pii> rotation;
    rotation.push_back(make_pair(num - 1, direction));

    // 왼쪽
    for (int j = num - 1; j > 0; j--) {
      if (circle[j - 1][2] != circle[j][6]) {
        int mul =
            (((num - 1) % 2) == ((j - 1) % 2)) ? direction : direction * -1;
        rotation.push_back(make_pair(j - 1, mul));
      } else
        break;
    }
    // 오른쪽
    for (int j = num - 1; j < 3; j++) {
      if (circle[j][2] != circle[j + 1][6]) {
        int mul =
            (((num - 1) % 2) == ((j + 1) % 2)) ? direction : direction * -1;
        rotation.push_back(make_pair(j + 1, mul));
      } else
        break;
    }

    for (int i = 0; i < rotation.size(); i++) {
      circle[rotation[i].first] =
          rotate(circle[rotation[i].first], rotation[i].second);
    }
  }

  int count = 0;
  if (circle[0][0] == 1)
    count += 1;
  if (circle[1][0] == 1)
    count += 2;
  if (circle[2][0] == 1)
    count += 4;
  if (circle[3][0] == 1)
    count += 8;

  cout << count;

  return 0;
}
