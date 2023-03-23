#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	char susik[101];
	scanf("%s", susik);

	//우선순위: +- < */ < 괄호 -> 괄호 안에서는 바뀔수있음
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

		//넣어주기 전에 괄호 있다면 괄호 먼저 제거
		//(수식)(수식) 이렇게 안들어와서 가능함
		//(수식)operator(수식) 이니까 무조건 괄호 제거해야함
		if (s.top() == ')') {
			s.pop();//괄호 출력안함
			while (s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			}
			s.pop();//괄호 출력안함
		}

		if (susik[i] == '*' || susik[i] == '/') {
			//*/만 없애기
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				printf("%c", s.top());
				s.pop();
			}
			s.push(susik[i]);
		}
		else if (susik[i] == '+' || susik[i] == '-') {
			//*/+- 없애기... 경우의 수가 */+-( 이렇게 다섯개임
			while (!s.empty() && s.top() != '(') {
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