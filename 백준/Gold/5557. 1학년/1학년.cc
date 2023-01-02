#include <iostream>
#include <vector>
using namespace std;

int arr[100];
long long dp[21];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[arr[0]]++;
	vector<pair<int, long long>> base;
	for (int i = 1; i < N - 1; i++) {
		int add_num = arr[i];
		if (add_num == 0) {
			for (int j = 0; j < 21; j++) dp[j] *= 2;
			continue;
		}
		base.clear();
		for (int j = 0; j < 21; j++) {
			if (dp[j] != 0) {
				base.push_back({ j, dp[j] });
				dp[j] = 0;
			}
		}
		for (pair<int, long long> b : base) {
			int base_num = b.first;
			long long base_cnt = b.second;
			if (base_num - add_num >= 0) dp[base_num - add_num] += base_cnt;
			if (base_num + add_num < 21) dp[base_num + add_num] += base_cnt;
		}
	}
	printf("%lld", dp[arr[N - 1]]);
}