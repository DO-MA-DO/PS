#include <string>
#include <vector>

using namespace std;

bool is_in[8];
vector<int> nPm;
int K;
int dn;
int max_cnt = -1;;

void per(vector<vector<int>> dungeons) {
    if(nPm.size() == dn) {
        //선택된 순서로 던전 
        int cur = K;
        int cnt = 0;
        for(int i: nPm) {
            if(dungeons[i][0] > cur) break;
            cur -= dungeons[i][1];
            cnt++;
        }
        if(cnt > max_cnt) max_cnt = cnt;
        return;
    }
    
    
    for(int i = 0; i<dn; i++) {
        if(is_in[i]) continue;
        is_in[i] = true;
        nPm.push_back(i);
        per(dungeons);
        nPm.pop_back();
        is_in[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    K=k;
    dn = dungeons.size();
    per(dungeons);
    answer = max_cnt;
    return answer;
}