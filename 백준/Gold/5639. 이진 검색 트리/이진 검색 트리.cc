#include <iostream>
using namespace std;

int N;
int node[10000];

void post_order(int si, int ei) {
	if (si > ei) return;
	int root = node[si];

	int leftlen = 0;
	for (int i = si + 1; i <= ei; i++) {
		if (node[i] > root) {
			break;
		}
		leftlen++;
	}
	//left
	post_order(si + 1, si + leftlen);
	//right
	post_order(si + leftlen + 1, ei);
	printf("%d\n", root);
}

int main() {
	N = 0;
	while (scanf("%d", &node[N]) != EOF) {
		N++;
	}
	post_order(0, N - 1);
}