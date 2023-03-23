#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int dp[100001];

int dfs(int here) {
	if (dp[here] != 0) {
		return dp[here];
	}

	dp[here] = 1;
	for (int nxt : tree[here]) {
		if (dp[nxt] == 0) {
			dp[here] += dfs(nxt);
		}
	}
	return dp[here];
}

int main() {
	int N, R, Q;
	scanf("%d%d%d", &N, &R, &Q);

	int u, v;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int U;
	while(Q--) {
		scanf("%d", &U);
		dfs(R);
		printf("%d\n", dfs(U));
	}
}