#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main() {
    char num[11];
    scanf("%s", num);
    int len = 0;
    for (int i = 0; num[i] != '\0'; i++) {
        arr[i] = num[i] - '0';
        len++;
    }
    sort(arr, arr + len, greater<>());
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
}