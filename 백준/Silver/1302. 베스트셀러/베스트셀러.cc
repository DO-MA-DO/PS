#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

unordered_map <string, int> um;
vector<pair<string, int>> v;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second > p2.second;
}

int main() {
	int N;
	scanf("%d", &N);
	char bn[51];
	int idx = 0;
	while (N--) {
		scanf("%s", bn);
		string s(bn);
		if (um.find(s) == um.end()) {
			um.insert({ s, idx++ });
			v.push_back({s, 0});
		}
		else {
			v[um[s]].second++;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	strcpy(bn, v[0].first.c_str());
	printf("%s", bn);
}