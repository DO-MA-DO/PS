#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
	int i, j, dir;
	bool eaten;
};

int max_ans = -1;
//0: 상어

int didj[9][2] = { {0, 0},
	{-1, 0}, {-1, -1}, {0, -1}, {1, -1},
	{1, 0}, {1, 1}, {0, 1}, {-1, 1} };

void fish_move(vector<info> &fish, vector<vector<int>> &map) {
	int fish_cnt = 0;
	for (int k = 1; k <= 16; k++) {
		if (fish[k].eaten) continue;
		fish_cnt++;
		int fi = fish[k].i;
		int fj = fish[k].j;
		int d = fish[k].dir;

		int ni, nj;
		while (true) {
			ni = fi + didj[d][0];
			nj = fj + didj[d][1];
			if (ni < 0 || ni>3 || nj < 0 || nj>3 || map[ni][nj] == -1) {
				d++;
				if (d > 8) d = 1;
				continue;
			}
			break;
		}
		fish[k].dir = d;

		//공란인 경우
		if (map[ni][nj] == 0) {
			//fish[k]의 위치 정보 공란으로 이동
			fish[k].i = ni;
			fish[k].j = nj;
			//map에도 반영해주기
			map[ni][nj] = map[fi][fj];
			map[fi][fj] = 0;
		}
		else {
			//fifj에 있는 fish와 ninj에 있는 fish 위치 바꿔주기
			swap(fish[map[ni][nj]].i, fish[map[fi][fj]].i);
			swap(fish[map[ni][nj]].j, fish[map[fi][fj]].j);
			//맵에서도 바꿔주기
			swap(map[ni][nj], map[fi][fj]);
		}
	}
}

void backtracking(int sum, vector<info> &fish, vector<vector<int>> &map) {
	fish_move(fish, map);

	info shark = fish[0];
	//갈 수 있는 곳(최대 3곳) 보기
	for(int k = 1; k <= 3; k++) {
		int ni = shark.i + didj[shark.dir][0] * k;
		int nj = shark.j + didj[shark.dir][1] * k;
		if (ni < 0 || ni>3 || nj < 0 || nj>3 || map[ni][nj] <= 0) continue;

		vector<info> fish_tmp(fish);
		vector<vector<int>> map_tmp(map);

		int fishnum = map[ni][nj];
		//상어 이동, 방향 바꾸기
		fish_tmp[0].i = ni;
		fish_tmp[0].j = nj;
		fish_tmp[0].dir = fish_tmp[fishnum].dir;
		//잡아먹힌 상태 표시
		fish_tmp[fishnum].eaten = true;
		//map 반영
		map_tmp[shark.i][shark.j] = 0;
		map_tmp[ni][nj] = -1;
		backtracking(sum + fishnum, fish_tmp, map_tmp);
	}
	max_ans = max(max_ans, sum);
}

int main() {
	//0: 상어
	vector<info> fish;
	vector<vector<int>> map(4, vector<int>(4));
	
	for (int i = 0; i <= 16; i++) {
		fish.push_back({ 0, 0, 0, true });
	}
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d%d", &a, &b);
			fish[a] = { i, j, b, false };
			map[i][j] = a;
		}
	}

	int first_fish_num = map[0][0];
	fish[0].eaten = false;
	fish[0].dir = fish[first_fish_num].dir;
	fish[first_fish_num].eaten = true;
	map[0][0] = -1;

	int day = 0;
	backtracking(first_fish_num, fish, map);
	printf("%d", max_ans);
}