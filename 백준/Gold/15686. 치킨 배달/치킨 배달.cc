#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Point {
	int x, y;
};

int N, M;
vector<Point> chickPoint;
vector<Point> housePoint;
vector<int> chickDiss;
int dosiMinchickDis = 10000000;

vector<int> nCm;
void backtracking(int start) {
	if (nCm.size() == M) {
		for (auto house : housePoint) {
			int minChickDis = 1000000;
			for (auto chickIdx : nCm) {
				int chickDis = 0;
				chickDis += abs(chickPoint[chickIdx].x - house.x);
				chickDis += abs(chickPoint[chickIdx].y - house.y);
				if (chickDis < minChickDis) minChickDis = chickDis;
			}
			chickDiss.push_back(minChickDis);
		}
		int dosiChickDis = 0;
		for (auto i : chickDiss) dosiChickDis += i;
		chickDiss.clear();
		if (dosiChickDis < dosiMinchickDis) dosiMinchickDis = dosiChickDis;
		return;
	}
	for (int i = start; i < chickPoint.size(); i++) {
		nCm.push_back(i);
		backtracking(i + 1);
		nCm.pop_back();
	}
}

int main() {
	scanf("%d%d", &N, &M);

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			if (tmp == 1) {
				housePoint.push_back({ i, j });
			}
			else if (tmp == 2) {
				chickPoint.push_back({ i, j });
			}
		}
	}

	backtracking(0);
	printf("%d", dosiMinchickDis);
}