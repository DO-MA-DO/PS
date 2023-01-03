#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int sum[3] = {0, 0, 0};
int arr1[4] = {1, 3, 4, 5};
int arr2[5] = {3, 1, 2, 4, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i = 0; i<answers.size(); i++) {
        int ans = answers[i];
        int p = i/2;
        //1번 채점
        if(ans == (i%5)+1) sum[0]++;
        //2번 채점
        if((i&1) == 0) {
            if(ans == 2) sum[1]++;
        }
        else {
            if(ans == arr1[p%4]) sum[1]++;
        }
        //3번 채점
        if(ans == arr2[p%5]) sum[2]++;
    }
    
    int ms = -1;
    for(int i = 0; i<3; i++) {
        ms = max(sum[i], ms);
    }
    for(int i = 0; i<3; i++) {
        if(sum[i] == ms) answer.push_back(i+1);
    }
    return answer;
}