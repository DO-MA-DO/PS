#include <string>
#include <vector>

using namespace std;

bool visit[200];
int N;

void dfs(int here, vector<vector<int>> com) {
    visit[here] = true;
    
    for(int i = 0; i<N; i++) {
        if(com[here][i] == 1 && !visit[i]) {
            dfs(i, com);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    for(int i = 0; i<n; i++) {
        if(!visit[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}