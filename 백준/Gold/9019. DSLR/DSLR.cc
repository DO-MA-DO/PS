#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool visit[10000];

string bfs(int si, int ei) {
	queue<pair<int, string>> q;
	string c = "";
	q.push({ si, c });
	visit[si] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		string cmd = q.front().second;
		q.pop();
		if (cur == ei) return cmd;

		//D
		int nxt = (cur * 2) % 10000;
		if (!visit[nxt]) {
			visit[nxt] = true;
			q.push({nxt, cmd + 'D'});
		}
		//S
		nxt = cur;
		if (--nxt == -1) nxt = 9999;
		if (!visit[nxt]) {
			visit[nxt] = true;
			q.push({ nxt, cmd + 'S' });
		}

		//L
		nxt = cur;
		int nxt_front = nxt / 1000;
		nxt = (nxt * 10 + nxt_front) % 10000;
		if (!visit[nxt]) {
			visit[nxt] = true;
			q.push({ nxt, cmd + 'L' });
		}

		//R 
		nxt = cur;
		int il = nxt % 10;
		nxt = (nxt / 10 + il*1000);
		if (!visit[nxt]) {
			visit[nxt] = true;
			q.push({ nxt, cmd + 'R' });
		}
	}
	return "err";
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int A, B;
		scanf("%d%d", &A, &B);

		for (int i = 0; i < 10000; i++) {
			visit[i] = false;
		}
		printf("%s\n", bfs(A, B).c_str());
	}
}