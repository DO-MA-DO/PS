#include <iostream>
#include <algorithm>
using namespace std;

int find_gcd(int a, int b) {
	if (a % b == 0) return b;
	return find_gcd(b, a % b);
}

int main() {
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	int gcd;
	if (n1 > n2) gcd = find_gcd(n1, n2);
	else gcd = find_gcd(n2, n1);
	//오버플로안남
	printf("%d\n%d", gcd, n1*n2/gcd);
}