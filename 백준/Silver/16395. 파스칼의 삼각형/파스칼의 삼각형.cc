#include <iostream>
#include <algorithm>
using namespace std;

int pas[30][30];
int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	pas[0][0] = 1;
	for (int i = 0; i < N; i++) {
		pas[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
	printf("%d", pas[N-1][K-1]);
}