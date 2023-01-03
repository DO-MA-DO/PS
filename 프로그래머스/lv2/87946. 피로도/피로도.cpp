#include <string>
#include <vector>

using namespace std;

bool check[8];

int K;
int dn;
int max_cnt = -1;;

void dfs(int cur, int cnt,  vector<vector<int>> dungeons) {
    if(cnt > max_cnt) max_cnt = cnt;
    
    for(int i = 0; i<dungeons.size(); i++) {
        if(cur >= dungeons[i][0] && !check[i]) {
            check[i] = true;
            dfs(cur-dungeons[i][1], cnt+1, dungeons);
            check[i] = false;
        }
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    K=k;
    dn = dungeons.size();
    dfs(k, 0, dungeons);
    answer = max_cnt;
    return answer;
}