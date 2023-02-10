#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct info {
	int num, cnt;
};

int arr[500000];
int cnt[8001];

bool cmp(const info& i1, const info& i2) {
	if (i1.cnt == i2.cnt) return i1.num < i2.num;
	return i1.cnt > i2.cnt;
}

int main() {
	int N;
	scanf("%d", &N);

	double sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i] + 4000]++;
		sum += arr[i];
	}

	int ans1 = round(sum / N);
	sort(arr, arr + N);
	int ans2 = arr[N / 2];

	int ans3;
	vector<info> v;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == 0) continue;
		v.push_back({ i - 4000, cnt[i] });
	}
	sort(v.begin(), v.end(), cmp);
	if (v.size() >=2 && v[0].cnt == v[1].cnt) ans3 = v[1].num;
	else ans3 = v[0].num;
	int ans4 = arr[N - 1] - arr[0];

	printf("%d\n%d\n%d\n%d", ans1, ans2, ans3, ans4);
}