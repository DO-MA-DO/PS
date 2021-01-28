#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
	stack <char> s;
	string str;
	getline(cin, str);
	
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '(') {
			if (str.at(i + 1) == ')') {//레이저임
				if (!s.empty()) {//스택에 들어있는 '(' 개수만큼 잘린 개수 늘어남
					ans += s.size();
					printf("---레이저---%d만큼 추가했다\n", s.size());
					printf("막대기 개수 : %d\n\n", ans);
				}
				else {//안잘림
					printf("---안잘리는 레이저---\n");
				}
				i++;
			}
			else {//막대기 왼쪽 끝
				s.push('(');
				ans++;
				printf("새 막대기임\n막대기 개수 : %d\n", ans);
			}
		}
		else {// ) 닫는 괄호 들어옴
			s.pop();// VPS이므로 stack이 비어있는데 들어올 리 없음
			printf("\npop함\nstack 안의 ( 개수 : %d\n", s.size());
		}

	}
	printf("이건듯\n");
	printf("%d", ans);

}