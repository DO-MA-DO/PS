#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long ans = 0;
vector<int> selec;
vector<int> num;

long long find_gcd(int x, int y) {
	if (x%y == 0) return y;
	else return find_gcd(y, x%y);
}

void nC2(int idx) {
	if (selec.size() == 2) {
		if(selec[0] > selec[1]) ans += find_gcd(selec[0], selec[1]);
		else ans += find_gcd(selec[1], selec[0]);
		return;
	}

	for (int i = idx; i < N; i++) {
		selec.push_back(num[i]);
		nC2(i + 1);
		selec.pop_back();
	}
}

int main() {
	int TC;
	scanf("%d", &TC);

	while (TC--) {
		scanf("%d", &N);

		num.clear();
		ans = 0;
		int tmp;
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			num.push_back(tmp);
		}
		nC2(0);

		printf("%lld\n", ans);
	}
}