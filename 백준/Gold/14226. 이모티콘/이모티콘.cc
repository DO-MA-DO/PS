#include <iostream>
#include <queue>
using namespace std;

int S;
//num, clipboard
bool visit[2000][2000];
struct info {
	int num, clip, cnt;
};

bool in_bound(int x, int y) {
	if (x < 0 || x >= 2000 || y < 0 || y >= 2000) return false;
	return true;
}

int bfs() {
	queue<info> q;
	q.push({1, 0, 0});
	visit[1][0] = true;

	while (!q.empty()) {
		int cur = q.front().num;
		int clip = q.front().clip;
		int cnt = q.front().cnt;
		q.pop();

		if (cur == S) return cnt;
		
		if (!visit[cur][cur]) {
			visit[cur][cur] = true;
			q.push({ cur, cur, cnt + 1 });
		}
		if (in_bound(cur + clip, clip) && !visit[cur + clip][clip]) {
			visit[cur + clip][clip] = true;
			q.push({ cur + clip, clip, cnt + 1 });
		}
		if (in_bound(cur - 1, clip) && !visit[cur - 1][clip]) {
			visit[cur - 1][clip] = true;
			q.push({ cur - 1, clip, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	scanf("%d", &S);
	printf("%d", bfs());
}