#include <iostream>
#include <queue>
using namespace std;

int N, M;
//치즈 밖 공기: 2;
int map[100][100];
bool visit[100][100];
int didj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

//치즈 밖에서부터 bfs 해야되는 이유
//: 치즈 안에 있는 공기는 무시하기 때문
void air_outside() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = true;
	map[0][0] = 2;
	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = ci + didj[k][0];
			int nj = cj + didj[k][1];
			if (ni < 0 || ni >= N || nj < 0 || nj >= M || visit[ni][nj] || map[ni][nj] == 1) continue;
			visit[ni][nj] = true;
			map[ni][nj] = 2;
			q.push({ni, nj});
		}
	}
}

void melt_cheese() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 1) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ni = i + didj[k][0];
				int nj = j + didj[k][1];
				if (ni < 0 || ni >= N || nj < 0 || nj >= M || map[ni][nj] != 2) continue;
				cnt++;
			}
			if (cnt >= 2) map[i][j] = 0;
		}
	}
}

void init_visit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
}

bool all_melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ans = 0;
	while (true) {
		if (all_melt()) break;
		air_outside();
		init_visit();
		melt_cheese();
		ans++;
	}
	printf("%d", ans);
}