#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string str;;

void solve(int si, int len) {
	if (len == 1) return;

	int mi = si + len / 3;
	for (int i = mi; i < mi + len / 3; i++) {
		str[i] = ' ';
	}
	solve(si, len/3);
	solve(mi + len / 3, len / 3);
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		str.clear();
		str.append(pow(3, N), '-');
		solve(0, pow(3, N));
		printf("%s\n", str.c_str());
	}
}