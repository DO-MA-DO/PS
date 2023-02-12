#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	char row[51];
	scanf("%s", row);
	
	//+ 연산 실행
	int sum = 0;
	vector<int> sums;
	string num = "";
	for (int i = 0; row[i] != '\0'; i++) {
		if (row[i] == '+') {
			sum += stoi(num);
			num = "";
		}
		else if (row[i] == '-') {
			sum += stoi(num);
			sums.push_back(sum);
			sum = 0;
			num = "";
		}
		else {
			num += row[i];
		}
	}
	sum += stoi(num);
	sums.push_back(sum);
	int ans = sums[0];
	for (int i = 1; i < sums.size(); i++) {
		ans -= sums[i];
	}
	printf("%d", ans);
}