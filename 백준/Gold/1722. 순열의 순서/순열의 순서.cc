#include <iostream>
#include <algorithm>
using namespace std;

long long fac[21];
bool is_used[21];
int arr[21];

int main() {
	int N;
	scanf("%d", &N);
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
	}

	int cmd;
	long long K;
	scanf("%d", &cmd);
	if (cmd == 1) {
		scanf("%lld", &K);
		K--;
		for (int i = 1; i <= N; i++) {
			long long base = fac[N - i];
			long long mox = K / base;
			long long nmj = K % base;
			long long cnt = 0;
			for (int j = 1; j <= N; j++) {
				if (!is_used[j]) {
					if (cnt++ == mox) {
						printf("%d ", j);
						is_used[j] = true;
						break;
					}
				}
			}
			K = nmj;
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		long long ret = 1;
		for (int i = 1; i <= N; i++) {
			long long base = fac[N - i];
			int cnt = 0;
			for (int j = 1; j < arr[i]; j++) {
				if (!is_used[j]) cnt++;
			}
			ret += base * cnt;
			is_used[arr[i]] = true;
		}
		printf("%lld", ret);
	}
}