#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	
	int plus_hour = C / 60;
	C -= plus_hour * 60;

	B += C;
	if (B >= 60) {
		B -= 60;
		plus_hour++;
	}
	A += plus_hour;
	if (A >= 24) {
		A -= 24;
	}
	printf("%d %d", A, B);
}