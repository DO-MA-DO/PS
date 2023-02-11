#include <iostream>
#include <queue>
using namespace std;

struct info {
	int num, cnt;
};

bool visit[1000001];

int bfs(int N) {
	queue<info> q;
	q.push({N, 0});
	visit[N] = true;

	while (!q.empty()) {
		int cur = q.front().num;
		int cnt = q.front().cnt;
		visit[cur] = true;
		q.pop();
		
		if (cur == 1) {
			return cnt;
		}
		if (cur % 3 == 0 && !visit[cur / 3]) {
			q.push({ cur / 3, cnt + 1 });
		}
		if (!(cur & 1) && !visit[cur / 2]) {
			q.push({cur / 2, cnt + 1});
		}
		if (!visit[cur - 1]) {
			q.push({ cur - 1 , cnt + 1 });
		}
	}
	//1에 도달 못함
	return -1;
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d", bfs(N));
}