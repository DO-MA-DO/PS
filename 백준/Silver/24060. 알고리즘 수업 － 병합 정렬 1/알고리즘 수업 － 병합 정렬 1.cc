#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int ans = -1;
vector<int> arr;
int save_cnt = 0;

void my_merge(int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 0;
    static vector<int> tmp(N);
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        }
        else {
            tmp[t++] = arr[j++];
        }
    }
    while (i <= q) {
        tmp[t++] = arr[i++];
    }
    while (j <= r) {
        tmp[t++] = arr[j++];
    }
    for (int i = p, t = 0; i <= r; i++, t++) {
        arr[i] = tmp[t];
        if (++save_cnt == K) {
            ans = tmp[t];
        }
    }
}

void my_merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        my_merge_sort(p, q);
        my_merge_sort(q + 1, r);
        my_merge(p, q, r);
    }
}

int main() {
    int num;
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        arr.push_back(num);
    }
    my_merge_sort(0, N - 1);
    printf("%d", ans);
}