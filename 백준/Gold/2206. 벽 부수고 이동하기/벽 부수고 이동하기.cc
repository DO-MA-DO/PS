#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int i, j;
	bool broken;
};

int N, M;
bool map[1000][1000];
int cnt[1000][1000][2];
int didj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int bfs() {
	queue<Info> q;
	q.push({0, 0, false});
	cnt[0][0][0] = 1;

	while (!q.empty()) {
		Info cur = q.front();
		int cur_i = cur.i;
		int cur_j = cur.j;
		bool has_broken = cur.broken;
		q.pop();

		if (cur_i == N - 1 && cur_j == M - 1) {
			return cnt[cur_i][cur_j][has_broken];
		}

		for (int k = 0; k < 4; k++) {
			int ni = cur_i + didj[k][0];
			int nj = cur_j + didj[k][1];
		
			if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if (cnt[ni][nj][has_broken] != 0) continue;
			
			//벽인 경우
			if (map[ni][nj]) {
				if (has_broken) continue;
				//뚫고 들어가보기
				cnt[ni][nj][1] = cnt[cur_i][cur_j][0] + 1;
				q.push({ni, nj, true});
			}
			else {
				//벽 아니면 그냥 진행 ㄱㄱ
				cnt[ni][nj][has_broken] = cnt[cur_i][cur_j][has_broken] + 1;
				q.push({ ni, nj, has_broken });
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &M);
	char row[1001];
	for (int i = 0; i < N; i++) {
		scanf("%s", row);
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j] - '0';
		}
	}

	printf("%d", bfs());
}