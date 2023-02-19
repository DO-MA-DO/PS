#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	int ans = 200000;
	int a, b;
	int min_a = 1001;
	int min_b = 1001;
	while (M--) {
		scanf("%d%d", &a, &b);
		min_a = min(min_a, a);
		min_b = min(min_b, b);
	}

	for (int i = 0; i <= N / 6 + 1; i++) {
		int nmj = N - 6 * i;
		if (nmj < 0) nmj = 0;
		ans = min(ans, min_a * i + min_b * nmj);
	}

	printf("%d", ans);
}