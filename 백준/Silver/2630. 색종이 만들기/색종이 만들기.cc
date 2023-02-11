#include <iostream>
using namespace std;

int cnt_blue = 0;
int cnt_white = 0;

bool is_blue[128][128];

void divide(int si, int sj, int n) {
	if (n == 0) return;
	bool all_blue = true;
	bool all_white = true;
	for (int i = si; i < si + n; i++) {
		for (int j = sj; j < sj + n; j++) {
			if (is_blue[i][j]) {
				all_white = false;
			}
			else {
				all_blue = false;
			}
		}
	}
	if (all_blue) {
		cnt_blue++;
		return;
	}
	else if (all_white) {
		cnt_white++;
		return;
	}
	//divide 하러 가야지~
	int half = n / 2;
	divide(si, sj, half);
	divide(si, sj + half, half);
	divide(si + half, sj, half);
	divide(si + half, sj + half, half);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &is_blue[i][j]);
		}
	}
	divide(0, 0, N);
	printf("%d\n%d", cnt_white, cnt_blue);
}