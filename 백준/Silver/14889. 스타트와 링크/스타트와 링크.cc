// 14889
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int> > capacity(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> capacity[i][j];
    }
  }

  vector<int> people(n, 1);
  for (int i = 0; i < n / 2; i++) {
    people[i] = 0;
  }

  int minGap = 987654321;
  do {
    int startScore = 0, linkScore = 0;
    vector<int> startTeam;
    vector<int> linkTeam;

    for (int i = 0; i < n; i++) {
      if (people[i] == 1) {
        startTeam.push_back(i);
      } else {
        linkTeam.push_back(i);
      }
    }

    for (int i = 0; i < n / 2; i++) {
      for (int j = i + 1; j < n / 2; j++) {
        startScore += capacity[startTeam[i]][startTeam[j]];
        startScore += capacity[startTeam[j]][startTeam[i]];

        linkScore += capacity[linkTeam[i]][linkTeam[j]];
        linkScore += capacity[linkTeam[j]][linkTeam[i]];
      }
    }

    int gap = startScore > linkScore ? startScore - linkScore
                                     : linkScore - startScore;

    if (minGap > gap)
      minGap = gap;
  } while (next_permutation(people.begin(), people.end()));

  cout << minGap;

  return 0;
}