#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    int mox = n/slice;
    int nmj = n%slice;
    answer = mox;
    if(nmj != 0) answer++;
    return answer;
}