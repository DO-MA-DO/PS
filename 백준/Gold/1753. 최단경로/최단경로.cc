#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 500000
using namespace std;

struct info {
	int node, shdis;
};

struct edge {
	int node, w;
};

struct cmp {
	bool operator()(const info& i1, const info& i2) {
		return i1.shdis > i2.shdis;
	}
};

priority_queue<info, vector<info>, cmp>pq;
vector<edge> adj_list[20001];
int dis[20001];

int main() {
	int V, E;
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++) {
		dis[i] = INF;
	}

	int K;
	scanf("%d", &K);
	pq.push({ K, 0 });
	dis[K] = 0;

	int u, v, w;
	while (E--) {
		scanf("%d%d%d", &u, &v, &w);
		bool dup = false;
		for (int i = 0; i < adj_list[u].size(); i++) {
			if (adj_list[u][i].node == v) {
				if (adj_list[u][i].w > w) adj_list[u][i].w = w;
				dup = true;
				break;
			}
		}
		if (!dup) adj_list[u].push_back({ v, w });
	}
	
	//dijk
	while (!pq.empty()) {
		int cur = pq.top().node;
		int cur_shdis = pq.top().shdis;
		pq.pop();

		if (cur_shdis > dis[cur]) continue;
		for (edge e : adj_list[cur]) {
			int next = e.node;
			if (cur_shdis + e.w < dis[next]) {
				dis[next] = cur_shdis + e.w;
				pq.push({ next, dis[next] });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) printf("INF\n");
		else printf("%d\n", dis[i]);
	}
}