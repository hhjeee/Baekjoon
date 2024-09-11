// 1043
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find_overlap(vector<int> arr1, vector<int> arr2) {
  for (int i = 0; i < (int)arr1.size(); i++) {
    for (int j = 0; j < (int)arr2.size(); j++) {
      if (arr1[i] == arr2[j]) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; // 사람수, 파티수
  cin >> n >> m;

  int real; // 진실을 아는 사람수
  vector<int> real_num;
  cin >> real;
  for (int i = 0; i < real; i++) {
    int num;
    cin >> num;
    real_num.push_back(num);
  }

  vector<vector<int> > people_num;
  for (int i = 0; i < m; i++) {
    int people;
    cin >> people;
    vector<int> party;
    for (int j = 0; j < people; j++) {
      int num;
      cin >> num;
      party.push_back(num);
    }
    people_num.push_back(party);
  }

  if (real == 0)
    cout << m;
  else {
    // 거짓을 아는 사람의 번호가 있는 파티 제외
    // 제외된 파티에 속해있는 사람이 있는 파티 제외
    // for문 다 돌렸을때 제외된 파티 없어야 while 종료

    int stop = 0;
    while (stop == 0) {
      int exclude_party = 0;

      for (int i = 0; i < m; i++) {
        if (people_num[i][0] == 51)
          continue;
        else {
          int exclude = find_overlap(real_num, people_num[i]);
          if (exclude) {
            exclude_party++;

            // real_num에 추가
            for (int j = 0; j < (int)people_num[i].size(); j++) {
              real_num.push_back(people_num[i][j]);
            }
            // 배열 중복제거
            sort(real_num.begin(), real_num.end());
            real_num.erase(unique(real_num.begin(), real_num.end()),
                           real_num.end());
            // 해당 파티배열 제거 - 다시 보지 않도록
            people_num[i][0] = 51;
          }
        }
      }

      if (!exclude_party)
        stop = 1;
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
      if (people_num[i][0] != 51)
        count++;
    }
    cout << count;
  }

  return 0;
}