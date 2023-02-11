#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001];

int main() {
	int N;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	printf("%d", dp[N]);
}