#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int mox = n/7;
    int nmj = n%7;
    if(nmj != 0) answer = mox+1;
    else answer = mox;
    return answer;
}