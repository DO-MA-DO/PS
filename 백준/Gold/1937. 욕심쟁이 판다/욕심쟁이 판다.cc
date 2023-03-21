#include <iostream>
using namespace std;

int N;
int map[500][500];
int visit[500][500];
int didj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int dfs(int si, int sj) {
	if (visit[si][sj] != 0) {
		return visit[si][sj];
	}
	
	bool all_small = true;
	for (int k = 0; k < 4; k++) {
		int ni = si + didj[k][0];
		int nj = sj + didj[k][1];
		//inbound, 조건
		if (ni < 0 || ni >= N || nj < 0 || nj >= N || map[ni][nj] <= map[si][sj]) continue;
		all_small = false;
		visit[si][sj] = max(visit[si][sj], dfs(ni, nj) + 1);
	}
	//return값 있어야함에 주의
	if (all_small) {
		visit[si][sj] = 1;
		return 1;
	}
	else {
		return visit[si][sj];
	}
}


int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				ans = max(ans, dfs(i, j));
			}
			else ans = max(ans, visit[i][j]);
		}
	}
	printf("%d", ans);
}