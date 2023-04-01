#include <iostream>
#include <algorithm>
using namespace std;

int sol[100000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &sol[i]);
	
	sort(sol, sol + N);

	int low = 0;
	int high = N - 1;
	int low_ans, high_ans;
	int sum = 0;
	int max_abs = 2000000001;
	while (low < high) {
		sum = sol[low] + sol[high];
		if (abs(sum) < max_abs) {
			low_ans = low;
			high_ans = high;
			max_abs = abs(sum);
		}
		if (sum > 0) high--;
		else if (sum < 0) low++;
		else break;
	}
	printf("%d %d", sol[low_ans], sol[high_ans]);
}