#include <iostream>
#include <algorithm>
#include <vector>
#define INF 500000
using namespace std;

vector<int> adj_list[50];
bool visit[50];
int rm_node;
int leaf_cnt = 0;

void dfs(int here) {
	visit[here] = true;

	bool is_leaf = true;
	for (int next : adj_list[here]) {
		if (!visit[next] && next != rm_node) {
			dfs(next);
			is_leaf = false;
		}
	}
	if (is_leaf) leaf_cnt++;
}

int main() {
	int N, parent, root;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &parent);
		if (parent != -1) adj_list[parent].push_back(i);
		else root = i;
	}
	scanf("%d", &rm_node);
	if(root != rm_node) dfs(root);
	printf("%d", leaf_cnt);
}