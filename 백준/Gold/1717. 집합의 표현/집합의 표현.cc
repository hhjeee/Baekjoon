// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> parent;
// vector<int> ranks;

// int find(int a) {
//   if (parent[a] != a) {
//     parent[a] = find(parent[a]);
//   }
//   return parent[a];
// }
// void unionSet(int a, int b) {
//   int rootA = find(a);
//   int rootB = find(b);

//   if (rootA != rootB) {
//     if (ranks[rootA] < ranks[rootB]) {
//       parent[rootA] = rootB;
//     } else if (ranks[rootA] > ranks[rootB]) {
//       parent[rootB] = rootA;
//     } else {
//       parent[rootB] = rootA;
//       ranks[rootA]++;
//     }
//   }
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);

//   int n, m;
//   cin >> n >> m;

//   parent.resize(n + 1);
//   ranks.resize(n + 1);

//   // n+1개의 집합 존재 (0부터 n까지)
//   for (int i = 1; i <= n; i++) {
//     parent[i] = i;
//     ranks[i] = 0;
//   }

//   for (int i = 0; i < m; i++) {
//     int cal, a, b;
//     cin >> cal >> a >> b;

//     if (cal == 0) {
//       // 합집합
//       unionSet(a, b);
//     } else if (cal == 1) {
//       // 같은 집합인지 확인 -> 루트 노드 비교
//       if (find(a) == find(b))
//         cout << "YES" << '\n';
//       else
//         cout << "NO" << '\n';
//     }
//   }

//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}
void uni_on(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA != rootB)
    parent[rootB] = rootA;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  parent.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  while (m--) {
    int c, a, b;
    cin >> c >> a >> b;

    if (c) {
      if (find(a) == find(b))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      uni_on(a, b);
    }
  }

  return 0;
}