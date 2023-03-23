#include <iostream>
#define MOD 1000000000
using namespace std;

long long pas[402][201];

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	for (int i = 0; i <= N + K - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) pas[i][j] = 1;
			else pas[i][j] = (pas[i - 1][j - 1] + pas[i - 1][j]) % MOD;
		}
	}
	printf("%d", pas[N + K - 1][N] % MOD);
}