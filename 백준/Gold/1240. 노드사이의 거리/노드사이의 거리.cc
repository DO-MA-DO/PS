#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
	int node, w;
};
int N;
vector<info> adj_list[1001];
bool visit[1001];

void init_visit() {
	for (int i = 1; i <= N; i++) {
		visit[i] = false;
	}
}


int bfs(int start, int end) {
	init_visit();
	queue<pair<int, int>> q;
	q.push({start, 0});
	visit[start] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();

		if (cur == end) return dis;

		for (info p : adj_list[cur]) {
			if (!visit[p.node]) {
				visit[p.node] = true;
				q.push({p.node, dis+p.w});
			}
		}
	}
	return -1;
}

int main() {
	int M;
	scanf("%d%d", &N, &M);

	int u, v, w;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		adj_list[u].push_back({ v, w });
		adj_list[v].push_back({ u, w });
	}

	while (M--) {
		scanf("%d%d", &u, &v);
		printf("%d\n", bfs(u, v));
	}
}