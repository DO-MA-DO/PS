#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000];
int B[1000];

int main() {
	int T;
	scanf("%d", &T);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	vector<int> a_bbh;
	for (int i = 0; i < N; i++) {
		int bbh = 0;
		for (int j = i; j < N; j++) {
			bbh += A[j];
			a_bbh.push_back(bbh);
		}
	}
	sort(a_bbh.begin(), a_bbh.end());
	vector<int> b_bbh;
	for (int i = 0; i < M; i++) {
		int bbh = 0;
		for (int j = i; j < M; j++) {
			bbh += B[j];
			b_bbh.push_back(bbh);
		}
	}
	long long ans = 0;
	for (int b : b_bbh) {
		ans += upper_bound(a_bbh.begin(), a_bbh.end(), T - b) - lower_bound(a_bbh.begin(), a_bbh.end(), T - b);
	}
	printf("%lld", ans);
}