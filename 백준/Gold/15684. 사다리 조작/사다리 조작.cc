#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int H, N;
bool map[32][12];
vector<pair<int, int>> hubo;
int hubo_size;

bool all_pass() {
	//세로: k
	for (int k = 1; k <= N; k++) {
		int pos = k;
		//내려가기
		for (int i = 1; i <= H; i++) {
			//왼쪽으로
			if (map[i][pos-1]) {
				pos--;
			}//오른쪽으로
			else if (map[i][pos]) {
				pos++;
			}
		}
		if (pos != k)  return false;
	}
	return true;
}

int ans_cnt = 5;
void bf(int cnt, int si) {
	if (ans_cnt < cnt) return;//가지치기
	if (all_pass()) {
		//min으로 안해도 됨
		ans_cnt = cnt;
		return;
	}
	if (cnt >= 3) {
		return;
	}

	for (int i = si; i < hubo_size; i++) {
		int ci = hubo[i].first;
		int cj = hubo[i].second;
		if (map[ci][cj] || map[ci][cj - 1] || map[ci][cj + 1]) continue;
		map[ci][cj] = true;
		bf(cnt + 1, i + 1);
		map[ci][cj] = false;
	}
}

int main() {
	int M;
	scanf("%d%d%d", &N, &M, &H);

	int pi, pj;
	while (M--) {
		scanf("%d%d", &pi, &pj);
		map[pi][pj] = true;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j < N; j++) {//N까지 후보에 안 넣어도 됨
			if (map[i][j] || map[i][j - 1] || map[i][j+1]) continue;
			hubo.push_back({ i, j });
		}
	}
	hubo_size = hubo.size();

	bf(0, 0);

	if (ans_cnt > 3) printf("-1");
	else printf("%d", ans_cnt);
}