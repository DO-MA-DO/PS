#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[8];
int N, M;
int max_idx;
vector<int> selected;

void nHm(int here) {
	if (selected.size() == M) {
		for (int i : selected) {
			printf("%d ", i);
		}
		printf("\n");
		return;
	}

	for (int i = here; i < max_idx; i++) {
		selected.push_back(arr[i]);
		nHm(i);
		selected.pop_back();
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	//sort 후 중복제거..erase는 안하고 인덱스만 쓰자
	sort(arr, arr + N);
	max_idx = unique(arr, arr + N) - arr;
	nHm(0);
}