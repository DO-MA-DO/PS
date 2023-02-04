#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	
	int M, num;
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &num);
		
		int low = 0;
		int high = N - 1;
		bool find = false;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (num < A[mid]) {
				high = mid - 1;
			}
			else if (num > A[mid]) {
				low = mid + 1;
			}
			else {
				find = true;
				break;
			}
		}
		if (find) printf("1\n");
		else printf("0\n");
	}
}