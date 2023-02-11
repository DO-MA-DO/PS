#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

bool broken[10];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int broken_num;
	while (M--) {
		scanf("%d", &broken_num);
		broken[broken_num] = true;
	}
	int press_btn_cnt1 = INT_MAX;
	//i 까지 버튼 눌러서 가기 + 이동하기 중 최소를 찾음
	//못가면 말고
	for (int i = 0; i <= 1000000; i++) {
		int cnt = 0;
		
		if (i == 0) {
			cnt = 1;
			if (broken[0]) continue;
		}

		bool able = true;
		int tmp = i;
		while (tmp) {
			if (broken[tmp % 10]) {
				able = false;
				break;
			}
			tmp /= 10;
			cnt++;
		}
		if (!able) continue;
		//N까지 이동하는것까지 구하기
		cnt += abs(N - i);
		press_btn_cnt1 = min(press_btn_cnt1, cnt);
	}

	//이동으로만 가기
	int press_btn_cnt2 = abs(N - 100);
	
	//둘 중 최소를 찾는다
	int ans = min(press_btn_cnt1, press_btn_cnt2);
	printf("%d", ans);
}