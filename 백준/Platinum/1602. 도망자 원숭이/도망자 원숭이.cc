#include <iostream>
#include <algorithm>
#include <vector>
#define INF 200000000
using namespace std;

int fw[501][501];
int ans[501][501];
int bullying[501];
vector<pair<int, int>> bullying_sort;
int mb;

//bullying 오름차순 정렬
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
	return p1.second < p2.second;
}

int main() {
	int N, M, Q;
	scanf("%d%d%d", &N, &M, &Q);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &bullying[i]);
		bullying_sort.push_back({ i, bullying[i] });
	}
	sort(bullying_sort.begin(), bullying_sort.end(), cmp);

	//init
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fw[i][j] = ans[i][j] = INF;
		}
		fw[i][i] = 0;
		ans[i][i] = bullying[i];
	}

	int a, b, d;
	while (M--) {
		scanf("%d%d%d", &a, &b, &d);
		fw[a][b] = d;
		fw[b][a] = d;
		int ans_d = d + max(bullying[a], bullying[b]);
		ans[a][b] = ans_d;
		ans[b][a] = ans_d;
	}

	for (int k = 0; k < N; k++) {
		int node = bullying_sort[k].first;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (fw[i][node] == INF || fw[node][j] == INF) continue;
				fw[i][j] = min(fw[i][j], fw[i][node] + fw[node][j]);
				int max_delay = max(max(bullying[i], bullying[j]), bullying[node]);
				ans[i][j] = min(ans[i][j], fw[i][node] + fw[node][j] + max_delay);
			}
		}
	}

	int S, T;
	while (Q--) {
		scanf("%d%d", &S, &T);

		if (ans[S][T] == INF) printf("-1\n");
		else printf("%d\n", ans[S][T]);
	}
}