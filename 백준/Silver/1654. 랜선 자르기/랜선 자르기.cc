#include <iostream>
#include <algorithm>
using namespace std;

int lanson[10000];

int main() {
	int K, N;
	scanf("%d%d", &K, &N);
	long long high = -1;
	for (int i = 0; i < K; i++) {
		scanf("%d", &lanson[i]);
		if (lanson[i] > high) high = lanson[i];
	}

	long long low = 1;
	long long ans = -1;
	while (low <= high) {
		long long cut = (high + low) / 2;
		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += lanson[i] / cut;
		}
		//성공! 그 중 cut의 최대를 찾음
		if (cnt >= N) {
			ans = max(ans, cut);
			low = cut + 1;
		}
		else {
			//실패! cnt가 너무 안나왔으므로
			//cut을 줄여야 함 -> high 떨어지기
			high = cut - 1;
		}
	}
	printf("%lld", ans);
}