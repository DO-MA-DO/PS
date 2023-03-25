#include <iostream>
#include <algorithm>
using namespace std;

int dp_max[3];
int dp_min[3];

int main() {
	int N;
	scanf("%d", &N);
	
	int s0, s1, s2;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &s0, &s1, &s2);
		int tmp_max0 = dp_max[0];
		int tmp_max1 = dp_max[1];
		int tmp_max2 = dp_max[2];
		int tmp_min0 = dp_min[0];
		int tmp_min1 = dp_min[1];
		int tmp_min2 = dp_min[2];
		//0번째 선택 0+0, 1+0
		dp_max[0] = max(tmp_max0 + s0, tmp_max1 + s0);
		dp_min[0] = min(tmp_min0 + s0, tmp_min1 + s0);
		//1번째 선택 0+1, 1+1, 2+1
		dp_max[1] = max(max(tmp_max0 + s1, tmp_max1 + s1), tmp_max2 + s1);
		dp_min[1] = min(min(tmp_min0 + s1, tmp_min1 + s1), tmp_min2 + s1);
		//2번째 선택 1+2, 2+2
		dp_max[2] = max(tmp_max1 + s2, tmp_max2 + s2);
		dp_min[2] = min(tmp_min1 + s2, tmp_min2 + s2);
	}

	printf("%d %d", max(max(dp_max[0], dp_max[1]), dp_max[2]), min(min(dp_min[0], dp_min[1]), dp_min[2]));
}