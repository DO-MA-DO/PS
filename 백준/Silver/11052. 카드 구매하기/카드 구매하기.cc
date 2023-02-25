#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
	int N, P;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &P);

		dp[i] = P;
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i-j]);
		}
	}
	printf("%d", dp[N]);
} 