#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;

		priority_queue<int> max_rm;
		priority_queue<int, vector<int>, greater<int>> min_rm;

		int K;
		scanf("%d", &K);
		getchar();
		char cmd;
		int queue_size = 0;
		int num;
		while (K--) {
			scanf("%c%d", &cmd, &num);
			getchar();

			if (cmd == 'D') {
				if (num == 1) {
					//max delete
					if (queue_size == 0) continue;

					//빼야되는거가 먼저 있으면 빼주기
					while (!max_rm.empty()) {
						if (max_rm.top() != max_heap.top()) break;
						max_rm.pop();
						max_heap.pop();
					}
					min_rm.push(max_heap.top());
					max_heap.pop();
					queue_size--;
				}
				else {
					//min delete
					if (queue_size == 0) continue;

					//빼야되는거가 먼저 있으면 빼주기
					while (!min_rm.empty()) {
						if (min_rm.top() != min_heap.top()) break;
						min_rm.pop();
						min_heap.pop();
					}
					max_rm.push(min_heap.top());
					min_heap.pop();
					queue_size--;
				}
			}
			else {
				//insert num
				queue_size++;
				max_heap.push(num);
				min_heap.push(num);
			}
		}
		if (queue_size == 0) {
			printf("EMPTY\n");
		}
		else {
			//빼야되는거가 먼저 있으면 빼주기
			while (!max_rm.empty()) {
				if (max_rm.top() != max_heap.top()) break;
				max_rm.pop();
				max_heap.pop();
			}
			while (!min_rm.empty()) {
				if (min_rm.top() != min_heap.top()) break;
				min_rm.pop();
				min_heap.pop();
			}
			printf("%d %d\n", max_heap.top(), min_heap.top());
		}
	}
}