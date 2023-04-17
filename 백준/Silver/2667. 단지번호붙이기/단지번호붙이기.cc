#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool map[25][25];
bool visit[25][25];
int didj[4][2] = { {1, 0}, {0, 1},
	{-1, 0}, {0, -1} };
int arr = 0;

void dfs(int hi, int hj) {
	visit[hi][hj] = true;
	++arr;

	for (int k = 0; k < 4; k++) {
		int ni = hi + didj[k][0];
		int nj = hj + didj[k][1];
		if (ni < 0 || ni >= N || nj < 0 || nj >= N || !map[ni][nj] || visit[ni][nj]) continue;
		dfs(ni, nj);
	}
}

int main() {
	scanf("%d", &N);
	char row[26];
	for (int i = 0; i < N; i++) {
		scanf("%s", row);
		for (int j = 0; j < N; j++) {
			map[i][j] = row[j] - '0';
		}
	}
	vector<int> arrs;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visit[i][j]) {
				arr = 0;
				dfs(i, j);
				arrs.push_back(arr);
			}
		}
	}
	printf("%d\n", arrs.size());
	sort(arrs.begin(), arrs.end());
	for (int a : arrs) {
		printf("%d\n", a);
	}
}