#include <iostream>
#include <vector>
using namespace std;

int inorder[100000];
int postorder[100000];

void pre_order(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e) return;
    
	int root = postorder[post_e];
	printf("%d ", root);
	int len = 0;
	for (int i = in_s; i <= in_e; i++) {
		if (inorder[i] == root) {
			break;
		}
		len++;
	}
	pre_order(in_s, in_s + len - 1, post_s, post_s + len - 1);
	pre_order(in_s + len + 1, in_e, post_s + len, post_e - 1);
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &inorder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &postorder[i]);
	}
	pre_order(0, N - 1, 0, N - 1);
}