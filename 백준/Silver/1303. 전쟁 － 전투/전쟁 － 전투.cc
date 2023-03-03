#include <iostream>
using namespace std;

int N, M;
bool is_blue[100][100];
bool visit[100][100];
int didj[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int area = 0;

void dfs(int hi, int hj) {
	visit[hi][hj] = true;
	area++;

	for (int k = 0; k < 4; k++) {
		int ni = hi + didj[k][0];
		int nj = hj + didj[k][1];

		if (ni < 0 || ni >= M || nj < 0 || nj >= N || visit[ni][nj] || is_blue[hi][hj] != is_blue[ni][nj]) continue;
		dfs(ni, nj);
	}
}

int main() {
	scanf("%d%d", &N, &M);

	char row[101];
	for (int i = 0; i < M; i++) {
		scanf("%s", row);
		for (int j = 0; j < N; j++) {
			if (row[j] == 'B') is_blue[i][j] = true;
		}
	}

	int blue_power = 0;
	int white_power = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j]) continue;
			area = 0;
			dfs(i, j);
			if (is_blue[i][j]) {
				blue_power += (area * area);
			}
			else {
				white_power += (area * area);
			}
		}
	}
	printf("%d %d", white_power, blue_power);
}