#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &s1, const string &s2) {
	if (s1.length() == s2.length()) return s1 < s2;
	return s1.length() < s2.length();
}

int main() {
	int N;
	scanf("%d", &N);
	char str[51];
	vector<string> v;
	while (N--) {
		scanf("%s", str);
		string s(str);
		v.push_back(s);
	}

	string before = "";
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		string s = v[i];
		strcpy(str, s.c_str());
		if (i != 0 && before == s) continue;
		printf("%s\n", str);
		before = s;
	}
}