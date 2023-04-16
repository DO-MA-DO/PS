#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj_list[100001];
bool visit[100001];
int far_node = -1;
int max_dis = -1;

void dfs(int here, int dis) {
	visit[here] = true;
	if (dis > max_dis) {
		max_dis = dis;
		far_node = here;
	}

	for (pair<int, int> p : adj_list[here]) {
		int next = p.first;
		if (!visit[next]) dfs(next, dis + p.second);
	}
}

int main() {
	int V;
	scanf("%d", &V);

	int n1;
	for(int i = 0; i<V; i++) {
		scanf("%d", &n1);
		int n2, w;
		while (true) {
			scanf("%d", &n2);
			if (n2 == -1) break;
			scanf("%d", &w);
			adj_list[n1].push_back({n2, w});
			adj_list[n2].push_back({n1, w});
		}
	}
	
	dfs(1, 0);
	for (int i = 1; i <= V; i++) {
		visit[i] = false;
	}
	dfs(far_node, 0);
	printf("%d", max_dis);
}