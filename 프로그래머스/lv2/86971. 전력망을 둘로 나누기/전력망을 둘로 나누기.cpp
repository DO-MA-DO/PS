#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visit[101];
int area = 0;


void dfs(int here, int idx, vector<vector<int>> wires) {
    //printf("here : %d\n", here);
    visit[here] = true;
    area++;
    
    for(int i = 0; i<wires.size(); i++) {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        if(v1 == here && i != idx && !visit[v2]) {
            dfs(v2, idx, wires);
        }
        if(v2 == here && i != idx && !visit[v1]) {
            dfs(v1, idx, wires);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i = 0; i<wires.size(); i++) {
        area = 0;
        dfs(1, i, wires);
        //printf("i: %d -> area: %d\n", i, area);
        answer = min(answer, abs(n-area-area));
        for(int j = 1; j<=n; j++) visit[j] = false;
    }
    return answer;
}