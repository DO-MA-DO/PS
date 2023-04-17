#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> X(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	vector<int> new_x(X);
	sort(new_x.begin(), new_x.end());
	new_x.erase(unique(new_x.begin(), new_x.end()), new_x.end());
	
	for (int i = 0; i < N; i++) {
		printf("%d ", lower_bound(new_x.begin(), new_x.end(), X[i]) - new_x.begin());
	}
}