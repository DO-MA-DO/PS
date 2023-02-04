#include <iostream>
#include <algorithm>
using namespace std;

bool not_prime[1000001];

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	not_prime[1] = true;
	for (int i = 2; i <= N; i++) {
		if (not_prime[i]) continue;
		for (int j = 2*i; j <= N; j += i) {
			not_prime[j] = true;
		}
	}
	for (int i = M; i <= N; i++) {
		if (!not_prime[i]) printf("%d\n", i);
	}
}