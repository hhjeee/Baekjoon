#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> score;
vector<int> teamA;
int min_val = INT_MAX;

int get_score(vector<int> &team) {
  int result = 0;
  for (int i = 0; i < team.size(); i++) {
    for (int j = i + 1; j < team.size(); j++) {
      result += score[team[i]][team[j]];
      result += score[team[j]][team[i]];
    }
  }

  return result;
}

void dfs(int idx) {
  if (idx == n) {
    if (teamA.size() == 0 || teamA.size() == n)
      return;

    vector<int> teamB;
    for (int i = 0; i < n; i++) {
      if (find(teamA.begin(), teamA.end(), i) == teamA.end())
        teamB.push_back(i);
    }

    int a_score = get_score(teamA);
    int b_score = get_score(teamB);

    min_val = min(min_val, abs(a_score - b_score));

    return;
  }

  teamA.push_back(idx);
  dfs(idx + 1);
  teamA.pop_back();

  dfs(idx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  score.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> score[i][j];
    }
  }

  dfs(0);

  cout << min_val;

  return 0;
}