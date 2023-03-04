#include <iostream>
using namespace std;

int N, M;
bool A[50][50];
bool B[50][50];
bool C[50][50];

bool has_dif() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (C[i][j]) return true;
		}
	}
	return false;
}

int main() {
	
	scanf("%d%d", &N, &M);

	char row[51];
	for (int i = 0; i < N; i++) {
		scanf("%s", row);
		for (int j = 0; j < M; j++) {
			if (row[j] == '1') A[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", row);
		for (int j = 0; j < M; j++) {
			if (row[j] == '1') B[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			C[i][j] = A[i][j] ^ B[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (C[i][j] && i + 2 < N && j + 2 < M) {
				ans++;
				for (int x = i; x < i + 3; x++) {
					for (int y = j; y < j + 3; y++) {
						C[x][y] = !C[x][y];
					}
				}
			}
		}
	}

	if (has_dif()) printf("-1");
	else printf("%d", ans);
}