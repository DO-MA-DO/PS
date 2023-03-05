#include <iostream>

int preorder[1000];
int inorder[1000];

void postorder(int s1, int e1, int s2, int e2) {
	if (s1 > e1 || s2 > e2) return;

	int root = preorder[s1];
	int left_len = 0;
	for (int i = s2; i <= e2; i++) {
		if (inorder[i] == root) {
			break;
		}
		left_len++;
	}
	
	//left
	postorder(s1 + 1, s1 + left_len, s2, s2 + left_len - 1);
	//right
	postorder(s1 + left_len + 1, e1, s2 + left_len + 1, e2);
	printf("%d ", root);
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &preorder[i]);
		}

		for (int i = 0; i < N; i++) {
			scanf("%d", &inorder[i]);
		}

		postorder(0, N - 1, 0, N - 1);
		printf("\n");
	}
}