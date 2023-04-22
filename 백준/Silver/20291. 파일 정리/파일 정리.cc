#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map<string, int> m;

int main() {
	int N;
	scanf("%d", &N);

	char file_name[50001];
	while (N--) {
		scanf("%s", file_name);
		string fn(file_name);
		fn = fn.substr(fn.find(".")+1);
		if (m.find(fn) == m.end()) {
			m.insert({ fn, 1 });
		}
		else {
			m[fn]++;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		printf("%s %d\n", it->first.c_str(), it->second);
	}
}