#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int T, N, M, tmp, idx, pri;

	scanf("%d", &T);
	while(T--) {

		queue <pair<int, int>> q;
		priority_queue <int> pq;

		int ans = 0;
		scanf("%d%d", &N, &M);

		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			q.push(make_pair(i, tmp));
			pq.push(tmp);
		}

		while (!q.empty()) {
			idx = q.front().first;
			pri = q.front().second;
			if (pri == pq.top()) {
				q.pop();
				ans++;
				pq.pop();
				if (idx == M) break;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		printf("%d\n", ans);
	}
}