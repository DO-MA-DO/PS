#include <iostream>
#include <algorithm>
#include <vector>
#define INF 500000
using namespace std;

int N;
int pop[11];
vector<int> adj_list[11];
vector<int> selected;
int total_pop = 0;
bool visit[11];
int min_diff;
int dfs_sum = 0;

void dfs_o(int here) {
	visit[here] = true;

	for (int next : adj_list[here]) {
		if (!visit[next]) {
			dfs_o(next);
		}
	}
}

void dfs(int here) {
	visit[here] = true;
	dfs_sum += pop[here];

	for (int next : adj_list[here]) {
		if (!visit[next]) {
			for (int s : selected) {
				if(next == s) dfs(next);
			}
		}
	}
}

void nCm(int here) {
	if (selected.size() == N) return;
	
	if (selected.size() > 0) {
		//두개로 나뉘는지 확인
		dfs_sum = 0;
		for (int i = 1; i <= N; i++) {
			visit[i] = false;
		}
		dfs(selected[0]);
		
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs_o(i);
				cnt++;
			}
		}
		if (cnt == 1) {
			min_diff = min(min_diff, abs(total_pop - 2*dfs_sum));
		}
	}

	for (int i = here; i <= N; i++) {
		selected.push_back(i);
		nCm(i + 1);
		selected.pop_back();
	}
}


int main() {
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &pop[i]);
		total_pop += pop[i];
	}
	min_diff = total_pop + 1;

	int adj_cnt;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &adj_cnt);
		int node;
		while (adj_cnt--) {
			scanf("%d", &node);
			adj_list[i].push_back(node);
			adj_list[node].push_back(i);
		}
	}

	nCm(1);
	if (min_diff == total_pop + 1) printf("-1");
	else printf("%d", min_diff);
}