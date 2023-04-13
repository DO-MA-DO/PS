#include <iostream>
#include <algorithm>
using namespace std;

int score[10000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}
	sort(score, score+N);

	long long ans = 0;
	int sum = 0;
	//3개의 합이 0
	//2개의 합이 score의 어느 값
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			sum = score[i] + score[j];
			ans += (upper_bound(score + j + 1, score + N, 0 - sum) - lower_bound(score + j + 1, score + N, 0 - sum));
		}
	}
	printf("%lld", ans);
}