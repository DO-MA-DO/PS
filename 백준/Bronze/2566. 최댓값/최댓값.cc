#include <iostream>
using namespace std;

int arr[9][9];

int main() {
	int max_val = -1;
	int mi = 0;
	int mj = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > max_val) {
				max_val = arr[i][j];
				mi = i+1;
				mj = j+1;
			}
		}
	}
	printf("%d\n%d %d", max_val, mi, mj);
}