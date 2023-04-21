#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];

int main() {
	int avg = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		avg += arr[i];
	}
	avg /= 5;
	sort(arr, arr + 5);
	printf("%d\n%d", avg, arr[2]);
}