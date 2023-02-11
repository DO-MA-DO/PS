#include <iostream>

int arr[128][128] = { 0, };
int N;
int blue = 0;
int white = 0;

void df(int x, int y, int n) {

	int half = n / 2;
	
	int cnt = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j]) cnt++;
		}
	}

	if (cnt == 0) {
		white++;
	}
	else if (cnt == n * n) {
		blue++;
	}
	else {
		df(x, y, half);
		df(x + half, y, half);
		df(x, y + half, half);
		df(x + half, y + half, half);
		return;
	}

}

int main() {
	
	scanf("%d", &N);

	int in;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &in);
			if (in) arr[i][j] = 1;
		}
	}

	df(0, 0, N);
	printf("%d\n%d", white, blue);
}