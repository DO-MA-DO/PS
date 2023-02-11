#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> max_heap;

int main() {
	int N;
	scanf("%d", &N);

	int cmd;
	while (N--) {
		scanf("%d", &cmd);

		if (cmd == 0) {
			if (max_heap.empty()) printf("0\n");
			else {
				printf("%d\n", max_heap.top());
				max_heap.pop();
			}
		}
		else {
			max_heap.push(cmd);
		}
	}
}