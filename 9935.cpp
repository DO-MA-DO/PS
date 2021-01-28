#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string boom;
	string ans;

	getline(cin, str);
	getline(cin, boom);

	int str_l = str.length();
	int boom_l = boom.length();

	char in;
	char b_last = boom.at(boom_l - 1);
	int isboom;
	int idx = 0;

	for (int i = 0; i < str_l; i++) {

		in = str.at(i);
		ans.append(1, in);

		//들어온 녀석이 폭탄의 마지막 녀석
		if (in == b_last) {

			int k = 0;
			//폭탄인지 확인
			for (int j = 0; j < boom_l; j++) {

				//cout <<"용의자 : "<< ans << endl << endl;
				//printf("-----\ni : %d\nj : %d\nidx : %d\n", i, j, idx);

				//인덱스(idx) 범위 벗어남 -> 일단 폭탄은 아님
				if (idx - j < 0) {
					isboom = 0;
					//cout << "2 : " << ans << endl << endl;
					break;
				}//폭탄 확인하는 부분(앞부분 문자열까지 확인)
				else  if (ans.at(idx - j) == boom.at(boom_l - 1 - j)) k++;

				//printf("ans[%d]와 boom[%d]를 비교했다\n", idx - j, boom_l - 1 - j);
				//printf("k : %d\n-----\n", k);

				//폭탄이다 아니다 판결 내림
				if (k == boom_l) isboom = 1;
				else isboom = 0;
			}

			//cout << "확인 끝 자유의 몸~" << endl << endl;
			//폭탄이 있으므로 boom 문자열 길이만큼 스택에서 뺴준다
			if (isboom) {
				for (int k = 0; k < boom_l; k++)
					ans.pop_back();

				idx -= boom_l;
			}


			//cout << "없애든가 말든가 함 : " << ans << endl << endl;
		}

		idx++;
	}
	if (ans.empty()) printf("FRULA");
	else cout << ans;
}