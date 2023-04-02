#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct info {
	int i, j, bc, cnt;
	bool in;
};

int N, M, K;
bool map[1000][1000];
bool dp[1000][1000][11];//visit
int ans[11];
int didj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void bfs() {
	queue<info> q;
	q.push({ 0, 0, 0, 1, true });
	dp[0][0][0] = true;

	while (!q.empty()) {
		int ci = q.front().i;
		int cj = q.front().j;
		int broken_cnt = q.front().bc;
		int cur_cnt = q.front().cnt;
		bool is_nat = q.front().in;
		q.pop();

		if (ci == N - 1 && cj == M - 1) {
			ans[broken_cnt] = cur_cnt;
			return;
		}

		for (int k = 0; k < 4; k++) {
			int ni = ci + didj[k][0];
			int nj = cj + didj[k][1];
			if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if (dp[ni][nj][broken_cnt]) continue;
			
			//벽임
			if (map[ni][nj]) {
				//음 두번째 조건은 의미 없으려나
				if (broken_cnt == K || dp[ni][nj][broken_cnt + 1]) continue;
				//낮이면 뚫기
				if (is_nat) {
					dp[ni][nj][broken_cnt + 1] = true;
					q.push({ ni, nj, broken_cnt + 1, cur_cnt + 1, !is_nat });
				}
				else {
					//가만히 있기
					q.push({ ci, cj, broken_cnt, cur_cnt + 1, !is_nat });
				}
			}
			else {
				//안뚫고 ㄱㄱ
				dp[ni][nj][broken_cnt] = true;
				q.push({ ni, nj, broken_cnt, cur_cnt + 1, !is_nat });
				//벽이 아닌데 가만히 있는 경우는.. 고려 안해도 될거같음
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	char row[1001];
	for (int i = 0; i < N; i++) {
		scanf("%s", row);
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j] - '0';
		}
	}
	bfs();
	
	bool unreachable = true;
	for (int i = 0; i <= K; i++) {
		if (ans[i] != 0) {
			unreachable = false;
			break;
		}
	}

	//도달 불가능
	if (unreachable) printf("-1");
	else {
		int min_ans = 2000000;
		for (int i = 0; i <= K; i++) {
			if (ans[i] == 0) continue;
			min_ans = min(min_ans, ans[i]);
		}
		printf("%d", min_ans);
	}
}