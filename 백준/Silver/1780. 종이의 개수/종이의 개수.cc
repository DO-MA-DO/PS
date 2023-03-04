#include <iostream>
using namespace std;

int map[2187][2187];
int zero_cnt, one_cnt, minus_cnt;
int didj[9][2] = {
	{0, 0}, {0, 1}, {0, 2},
	{1, 0}, {1, 1}, {1, 2},
	{2, 0}, {2, 1}, {2, 2}
};

void dq(int si, int sj, int len) {
	if (len < 0) return;

	int start = map[si][sj];
	bool divide = false;
	for (int i = si; i < si + len; i++) {
		if (divide) break;
		for (int j = sj; j < sj + len; j++) {
			if (map[i][j] != start) {
				divide = true;
				break;
			}
		}
	}

	if (divide) {
		int nl = len / 3;
		for (int k = 0; k < 9; k++) {
			dq(si + nl * didj[k][0], sj + nl * didj[k][1], nl);
		}
	}
	else {
		if (start == 0) zero_cnt++;
		else if (start == 1) one_cnt++;
		else minus_cnt++;
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for(int j = 0; j<N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dq(0, 0, N);
	printf("%d\n%d\n%d", minus_cnt, zero_cnt, one_cnt);
}