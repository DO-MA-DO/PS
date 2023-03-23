#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	char susik[101];
	scanf("%s", susik);

	//우선순위: +- < */ < (어쩌구)
	int str_len = strlen(susik);
	stack<char> s;
	for (int i = 0; i < str_len; i++) {
		if ('A' <= susik[i] && susik[i] <= 'Z') {
			printf("%c", susik[i]);
			continue;
		}
		if (s.empty()) {
			s.push(susik[i]);
			continue;
		}
		if (s.top() == '(') {
			s.push(susik[i]);
			continue;
		}
		if (susik[i] == '*' || susik[i] == '/') {
			if (s.top() == ')') {
				s.pop();//괄호 출력안함
				while (s.top() != '(') {
					printf("%c", s.top());
					s.pop();
				}
				s.pop();//괄호 출력안함
			}
			//*/ 없애기
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				printf("%c", s.top());
				s.pop();
				if (s.empty()) break;
			}
			s.push(susik[i]);
		}
		else if (susik[i] == '+' || susik[i] == '-') {
			if (s.top() == ')') {
				s.pop();//괄호 출력안함
				while (s.top() != '(') {
					printf("%c", s.top());
					s.pop();
				}
				s.pop();//괄호 출력안함
			}
			//다 없애면 안되고.... 괄호 안은 냄겨야됨
			while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')) {
				printf("%c", s.top());
				s.pop();
			}
			s.push(susik[i]);
		}
		else {//괄호
			s.push(susik[i]);
		}
	}
	while (!s.empty()) {
		if (s.top() != '(' && s.top() != ')') printf("%c", s.top());
		s.pop();
	}
}