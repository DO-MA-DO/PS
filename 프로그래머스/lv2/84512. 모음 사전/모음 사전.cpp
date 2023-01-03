#include <string>
#include <vector>

using namespace std;
char moum[5] = {'A', 'E', 'I', 'O', 'U'};
int idx = 0;
int ans;
bool found = false;

void nHm(string str, string word) {
    if(found) return;
    if(str.length() > 5) return;
    if(str.length() >= 1) idx++;
    if(str == word) {
        ans = idx;
        found = true;
        return;
    }
    
    for(int i = 0; i<5; i++) {
        string tmp(str);
        tmp += moum[i];
        nHm(tmp, word);
    }
}

int solution(string word) {
    int answer = 0;
    nHm("", word);
    answer = ans;
    return answer;
}