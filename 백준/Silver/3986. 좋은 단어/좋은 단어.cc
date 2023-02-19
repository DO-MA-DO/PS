#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	char row[100001];
	int ans = 0;
	while (N--) {
		scanf("%s", row);
		if (strlen(row) & 1) continue;
		stack<char> s;
		int mi = strlen(row);
		for (int i = 0; i < mi; i++) {
			if (s.size() > mi - i) break;
			if (s.empty()) s.push(row[i]);
			else if (s.top() == row[i]) {
				s.pop();
			}
			else {
				s.push(row[i]);
			}
		}
		if (s.empty()) ans++;
	}
	printf("%d", ans);
}