#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[100][70];
bool visit[100][70];
int didj[8][2] = {
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
	{1, 1}, {-1, -1}, {1, -1}, {-1, 1}
};

bool bfs(int si, int sj) {
	queue<pair<int, int>> q;
	q.push({si, sj});
	visit[si][sj] = true;

	vector<pair<int, int>> check;

	while (!q.empty()) {
		int cur_i = q.front().first;
		int cur_j = q.front().second;
		q.pop();

		check.push_back({cur_i, cur_j});

		for (int k = 0; k < 8; k++) {
			int ni = cur_i + didj[k][0];
			int nj = cur_j + didj[k][1];
			//높이 같은칸들 일단 큐에 넣기
			if (ni < 0 || ni >= N || nj < 0 || nj >= M || map[ni][nj]!=map[cur_i][cur_j] || visit[ni][nj]) continue;
			visit[ni][nj] = true;
			q.push({ni, nj});
		}
	}

	for (pair<int, int> p : check) {
		int i = p.first;
		int j = p.second;
		for (int k = 0; k < 8; k++) {
			int ni = i + didj[k][0];
			int nj = j + didj[k][1];
			if (ni < 0 || ni >= N || nj < 0 || nj >= M ) continue;
			if (map[ni][nj] > map[i][j]) return false;
		}
	}
	//다 통과하면 ㅇㅋ
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0 && !visit[i][j]) {
				if (bfs(i, j)) ans++;
			}
		}
	}
	printf("%d", ans);
}