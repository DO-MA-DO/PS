#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> conf[100000];

struct cmp {
	bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
		if (p1.second == p2.second) return p1.first < p2.first;
		return p1.second < p2.second;
	}
};

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d%d", &conf[i].first, &conf[i].second);
	}

	sort(conf, conf + N, cmp());

	int ans = 1;
	int end_time = conf[0].second;
	for (int i = 1; i < N; i++) {
		int start_time = conf[i].first;
		if (end_time <= start_time) {
			ans++;
			end_time = conf[i].second;
		}
	}
	printf("%d", ans);
}