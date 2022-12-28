#include <string>
#include <vector>
#include <queue>

using namespace std;
//max heap
priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    for(int e: enemy) {
        pq.push(e);
        n -= e;
        if(n<0) {
            if(k<=0) break;
            int max = pq.top();
            pq.pop();
            n += max;
            k--;
        }
        answer++;
    }
    return answer;
}