#include <string>
#include <vector>

using namespace std;
int arr[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    int answer = 0;
    for(int i = 0; i<word.length(); i++) {
        if(word[i]=='A') answer += arr[i]*0 + 1;
        else if(word[i] == 'E') answer += arr[i]*1 + 1;
        else if(word[i] == 'I') answer += arr[i]*2 + 1;
        else if(word[i] == 'O') answer += arr[i]*3 + 1;
        else if(word[i] == 'U') answer += arr[i]*4 + 1;
    }
    return answer;
}