#include <string>
#include <vector>
#include <algorithm>
#define TAN_MAX 10000000
using namespace std;

int cnt[TAN_MAX + 1];

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    int tan_max = -1;
    for(int t:tangerine) {
        tan_max = max(tan_max, t);
        cnt[t]++;
    }

    sort(cnt+1, cnt + tan_max + 1, greater<>());
    
    //답 계산
    for(int i = 1; i<=tan_max; i++) {
        k -= cnt[i];
        answer++;
        if(k<=0) break;
        if(cnt[i] == 0) break;//뒤에도 다 0이므로 볼 필요 없음
    }
    
    return answer;
}