#include <iostream>
#include <queue>
using namespace std;

int A, B;
int bfs() {
	queue<pair<long long, int>>q;
	q.push({ A, 1 });

	while (!q.empty()) {
		long long cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == B) {
			return cnt;
		}

		if (cur * 2 <= B) {
			q.push({ cur * 2, cnt + 1 });
		}
		long long num = cur * 10 + 1;
		if (num <= B) {
			q.push({ num, cnt + 1 });
		}
	}

	return -1;
}

int main() {
	scanf("%d%d", &A, &B);
	printf("%d", bfs());
}