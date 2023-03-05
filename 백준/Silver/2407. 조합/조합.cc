#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pas[101][101];

string string_hap(string s1, string s2) {
	string ret = "";
	int tmp = 0;
	int s1_len = s1.length();
	int s2_len = s2.length();
	for (int i = 0; i < s1_len || i < s2_len; i++) {
		if (i < s1_len) {
			tmp += s1[s1_len - 1 - i] - '0';
		}
		if (i < s2_len) {
			tmp += s2[s2_len - 1 - i] - '0';
		}
		ret += (tmp % 10) + '0';
		tmp /= 10;
	}
	if (tmp != 0) ret += (tmp % 10) + '0';
	
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) pas[i][j] = "1";
			else pas[i][j] = string_hap(pas[i - 1][j], pas[i - 1][j - 1]);
		}
	}

	cout << pas[N][M];
}