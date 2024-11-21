#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vi> student_class(n, vi(5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> student_class[i][j];
    }
  }

  vector<vi> same_student(n, vi(n, 0));
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 5; s++) {
      int tmp = student_class[i][s];
      for (int j = 0; j < n; j++) {
        if (tmp == student_class[j][s])
          same_student[i][j] = 1;
      }
    }
  }

  vi student_count(n, 0);
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (same_student[i][j] == 1)
        count++;
    }
    student_count[i] = count;
  }

  int max = 0;
  int max_student = 0;
  for (int i = 0; i < n; i++) {
    if (max < student_count[i]) {
      max = student_count[i];
      max_student = i + 1;
    }
  }

  cout << max_student;

  return 0;
}