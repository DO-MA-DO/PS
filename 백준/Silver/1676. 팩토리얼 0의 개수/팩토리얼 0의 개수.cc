#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime[501];
int prime_cnt[501];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) continue;
		for (int j = 2 * i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}

	for (int n = 1; n <= N; n++) {
		int tmp_n = n;
		for (int i = 2; i <= N; i++) {
			if (!is_prime[i]) continue;
			while ((tmp_n % i) == 0) {
				tmp_n /= i;
				prime_cnt[i]++;
			}
		}
	}

	printf("%d", min(prime_cnt[2], prime_cnt[5]));
}