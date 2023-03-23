#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
bool hol_visit[500001];
bool jjak_visit[500001];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	jjak_visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		int brother = K + (cnt * (cnt + 1) / 2);
		if (brother > 500000) return -1;
		if (cur == brother) {
			return cnt;
		}
		if (cnt & 1 && hol_visit[brother]) return cnt;
		if (!(cnt & 1) && jjak_visit[brother]) return cnt;

		int nxt = cur * 2;//next니까 홀수일때 짝수 visit 체크해주는거 조심
		if (nxt <= 500000 && (cnt & 1 ? !jjak_visit[nxt] : !hol_visit[nxt])) {
			cnt & 1 ? jjak_visit[nxt] = true : hol_visit[nxt] = true;
			q.push({ nxt , cnt + 1 });
		}
		nxt = cur + 1;
		if (nxt <= 500000 && (cnt & 1 ? !jjak_visit[nxt] : !hol_visit[nxt])) {
			cnt & 1 ? jjak_visit[nxt] = true : hol_visit[nxt] = true;
			q.push({ nxt , cnt + 1 });
		}
		nxt = cur - 1;
		if (nxt >= 0 && (cnt & 1 ? !jjak_visit[nxt] : !hol_visit[nxt])) {
			cnt & 1 ? jjak_visit[nxt] = true : hol_visit[nxt] = true;
			q.push({ nxt , cnt + 1 });
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &K);
	printf("%d", bfs());
}