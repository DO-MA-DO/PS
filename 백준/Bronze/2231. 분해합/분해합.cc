#include <iostream>
using namespace std;

//N = M + M의 자리수 다 더하기
//구할 수 있는 M의 최소값은 ?
int main() {
	int N;
	scanf("%d", &N);

	//브루트포스 가능할 거 같긴함
	//N이 1000000 이하의 값이고,
	//생성자인 M은 N 이하일 수 밖에 없으므로
	//1~1000000까지만 보면 됨
	
	//M 구하기
	int sum = 0;
	int ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		sum = i;
		int tmp = i;
		while (tmp) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		if (sum == N) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
}