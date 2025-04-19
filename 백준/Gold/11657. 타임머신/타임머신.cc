#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct edge {
	int from;
	int to;
	int cost;
};

vector<edge> edgeList;
vector<long long int> dist;

bool bellmanFord(int n) {
	dist[1] = 0;

	//v-1번 탐색
	for (int i = 0; i < n - 1; i++) {
		for (edge e : edgeList) {
			if (dist[e.from] == LONG_MAX) continue;

			if (dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] + e.cost;
			}
		}
	}

	//음의 사이클 검사
	bool negativeCycle = false;

	for (edge e : edgeList) {
		if (dist[e.from] == LONG_MAX) continue;

		if (dist[e.to] > dist[e.from] + e.cost) {
			negativeCycle = true;
			break;
		}
	}

	return negativeCycle;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	edgeList.resize(m);
	dist.resize(n + 1, LONG_MAX);

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		edgeList.push_back({ a, b, c });
	}

	bool haveNegativeCycle = bellmanFord(n);

	if (haveNegativeCycle) cout << -1;
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == LONG_MAX) cout << "-1\n";
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}
