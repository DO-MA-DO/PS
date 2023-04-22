#include <iostream>
#include <algorithm>
using namespace std;

int N, L, R;
int map[50][50];
int visit[50][50];
int didj[4][2] = { {1, 0 }, {0, 1}, {-1, 0}, {0, -1} };
int pop_sum, pop_cnt;

void dfs(int hi, int hj) {
	visit[hi][hj] = true;
	pop_cnt++;
	pop_sum += map[hi][hj];

	for (int k = 0; k < 4; k++) {
		int ni = hi + didj[k][0];
		int nj = hj + didj[k][1];
		if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
		int chai = abs(map[hi][hj] - map[ni][nj]);
		if (!visit[ni][nj] && L <= chai && chai <= R) {
			dfs(ni, nj);
		}
	}
}

void dfs_fill(int hi, int hj, int val) {
	visit[hi][hj] = 2;
	map[hi][hj] = val;

	for (int k = 0; k < 4; k++) {
		int ni = hi + didj[k][0];
		int nj = hj + didj[k][1];
		if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
		if (visit[ni][nj] == 1) {
			dfs_fill(ni, nj, val);
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	int ans = 0;
	while (true) {
		int dfs_call_cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					dfs_call_cnt++;
					pop_sum = 0;
					pop_cnt = 0;
					dfs(i, j);
					dfs_fill(i, j, pop_sum / pop_cnt);
				}
			}
		}
		if (dfs_call_cnt == N * N) break;
		ans++;
	}
	printf("%d", ans);
}