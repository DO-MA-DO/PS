#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int TC;
	scanf("%d", &TC);

	while (TC--) {
		char cmd[100001];
		scanf("%s", cmd);
		int N;
		scanf("%d", &N);
		char row[500000];
		scanf("%s", row);
		row[0] = ',';
		row[strlen(row) - 1] = ',';
		vector<int> arr;
		char *ptr = strtok(row, ",");
		while (ptr != NULL) {
			arr.push_back(atoi(ptr));
			ptr = strtok(NULL, ",");
		}

		int li = 0;
		int ri = N - 1;
		bool go_right = true;
		vector<int> ans;
		bool has_error = false;
		for (int i = 0; cmd[i] != '\0'; i++) {
			if (cmd[i] == 'R') {
				go_right = !go_right;
			}
			else {
				if (li > ri) {
					has_error = true;
					break;
				}
				if (go_right) li++;
				else ri--;
			}
		}


		if (has_error) printf("error\n");
		else {
			if (arr.empty() || li > ri) {
				printf("[]\n");
				continue;
			}
			printf("[");
			if (go_right) {
				for (int i = li; i < ri; i++) {
					printf("%d,", arr[i]);
				}
				printf("%d", arr[ri]);
			}
			else {
				for (int i = ri; i > li; i--) {
					printf("%d,", arr[i]);
				}
				printf("%d", arr[li]);
			}
			printf("]\n");
		}
	}
}