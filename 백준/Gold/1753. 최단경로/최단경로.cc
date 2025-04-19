#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200001;

struct node {
	int dest;
	int cost;
};
struct compare {
	bool operator() (node a, node b) {
		return a.cost > b.cost;
	}
};

vector<vector<node>> adjList;
vector<int> dist;

void dijkstra(int v, int start) {
	priority_queue<node, vector<node>, compare> pq;
	pq.push({ start, 0 });

	vector<bool> visited(v + 1);

	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();

		if (visited[cur.dest]) continue;

		visited[cur.dest] = true;

		for (node next : adjList[cur.dest]) {
			if (dist[next.dest] > next.cost + cur.cost) {
				dist[next.dest] = next.cost + cur.cost;
				pq.push(node{ next.dest, dist[next.dest] });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int v, e, k;
	cin >> v >> e >> k;

	adjList.resize(v + 1);
	dist.resize(v + 1, MAX);
	dist[k] = 0;

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back(node { v,w });
	}

	dijkstra(v, k);

	for (int i = 1; i <= v; i++) {
		if (dist[i] == MAX) cout << "INF\n";
		else cout << dist[i] << '\n';
	}


	return 0;
}