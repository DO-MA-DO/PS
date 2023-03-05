#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	char str[31];
	scanf("%s", str);

	int str_len = strlen(str);
	stack<char> s;
	
	bool not_okay = false;
	int ans = 0;
	int tmp = 1;
	for(int i = 0; i<str_len; i++){
		if (str[i] == '(') {
			s.push('(');
			tmp *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			tmp *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty()) {
				not_okay = true;
				break;
			}
			if (s.top() == '(') {
				s.pop();
				//처음부터 닫힘안들어오니까
				if (str[i - 1] != ')' && str[i - 1] != ']') {
					ans += tmp;
				}
				tmp /= 2;
			}
			else {
				not_okay = true;
				break;
			}
		}
		else if (str[i] == ']') {
			if (s.empty()) {
				not_okay = true;
				break;
			}
			if (s.top() == '[') {
				s.pop();
				if (str[i - 1] != ')' && str[i - 1] != ']') {
					ans += tmp;
				}
				tmp /= 3;
			}
			else {
				not_okay = true;
				break;
			}
		}
	}

	if (not_okay || !s.empty()) printf("0");
	else printf("%d", ans);
}