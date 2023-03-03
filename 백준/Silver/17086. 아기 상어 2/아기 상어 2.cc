#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool map[51][51];
bool visit[51][51];
int didj[8][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

void init_ds() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
}

struct info {
	int i;
	int j;
	int cnt;
};

int bfs(int si, int sj) {
	init_ds();
	queue<info> q;
	q.push({ si, sj, 0 });
	visit[si][sj] = true;

	while (!q.empty()) {
		int hi = q.front().i;
		int hj = q.front().j;
		int cur_cnt = q.front().cnt;
		q.pop();

		if (map[hi][hj]) return cur_cnt;

		for (int k = 0; k < 8; k++) {
			int ni = hi + didj[k][0];
			int nj = hj + didj[k][1];
			if (ni < 0 || ni >= N || nj < 0 || nj >= M || visit[ni][nj]) continue;
			visit[ni][nj] = true;
			q.push({ ni, nj, cur_cnt + 1 });
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				int tmp = bfs(i, j);
				if (tmp > ans) ans = tmp;
			}
		}
	}
	printf("%d", ans);
}