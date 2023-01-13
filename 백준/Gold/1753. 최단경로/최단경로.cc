#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 200001
using namespace std;

struct edge {
	int node, w_shdis;
};

struct cmp {
	bool operator()(const edge& e1, const edge& e2) {
		return e1.w_shdis > e2.w_shdis;
	}
};

vector<edge> adjList[20001];
priority_queue<edge ,vector<edge>, cmp> toStart;
int shdis[20001];
bool visit[20001];

int main() {
	int V, E;
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++) shdis[i] = INF;
	int K;
	scanf("%d", &K);
	shdis[K] = 0;
	toStart.push({ K, 0 });

	int u, v, w;
	while (E--) {
		scanf("%d%d%d", &u, &v, &w);
		bool is_dup = false;
		for (int i = 0; i < adjList[u].size(); i++) {
			int connected_node = adjList[u][i].node;
			int old_weight = adjList[u][i].w_shdis;
			if (connected_node == v) {
				adjList[u][i].w_shdis = min(old_weight, w);
				is_dup = true;
				break;
			}
		}
		if (!is_dup) adjList[u].push_back({ v, w });
	}

	while (!toStart.empty()) {
		int cur = toStart.top().node;
		int cur_shdis = toStart.top().w_shdis;
		toStart.pop();

		visit[cur] = true;

		if (cur_shdis > shdis[cur]) continue;

		for (edge next_e : adjList[cur]) {
			int next = next_e.node;
			int next_shdis = shdis[cur] + next_e.w_shdis;
			if (visit[next]) continue;

			if (shdis[next] > next_shdis) {
				shdis[next] = next_shdis;
				toStart.push({next, next_shdis });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (shdis[i] == INF) printf("INF\n");
		else printf("%d\n", shdis[i]);
	}
}