#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int N, K;
unordered_map<string, bool> um;
string startstring = "";
string endstring = "";
int max_idx;

int bfs() {
	queue<pair<string, int>> q;
	q.push({startstring, 0});
	um.insert({ startstring, true });

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == endstring) {
			return cnt;
		}

		for (int i = 0; i <= max_idx; i++) {
			string newstring(cur);
			reverse(newstring.begin() + i, newstring.begin() + i + K);
			if (um.find(newstring) == um.end()) {
				um.insert({newstring, true});
				q.push({ newstring, cnt + 1 });
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &N, &K);
	max_idx = N - K;
	
	char tmp;
	for (int i = 0; i < N; i++) {
		scanf(" %c", &tmp);
		startstring += tmp;
	}
	
	for (int i = 1; i <= N; i++) {
		endstring += (i + '0');
	}
	printf("%d", bfs());
}