#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char map[500][500];
int visit[500][500];//0000네자리 -> 15가 최대
//상, 우, 하, 좌
int didj[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<int> answer;

//시작점, 현재위치, dir, cnt 가지고 있어야 함
//시작점==현재위치 여야하고, ndir 가 sdir이어야 함 같은방향이어야함
void dfs(int si, int sj, int sdir, int hi, int hj, int dir, int cnt) {
    visit[hi][hj] += (1<<dir);
    //dir 바꾸기
    if (map[hi][hj] == 'R') dir = (dir + 1) % 4;
    else if (map[hi][hj] == 'L') {
        if (dir == 0) dir = 3;
        else dir--;
    }

    if (si == hi && sj == hj && dir == sdir) {
        answer.push_back(cnt);
        return;
    }

    //다음 위치 찾기
    int ni = hi + didj[dir][0];
    int nj = hj + didj[dir][1];
    if (ni < 0) ni = N - 1;
    else if (ni >= N) ni = 0;
    else if (nj < 0) nj = M - 1;
    else if (nj >= M) nj = 0;
    //이동
    if((visit[ni][nj] & (1<<dir))==0) dfs(si, sj, sdir, ni, nj, dir, cnt + 1);
}

vector<int> solution(vector<string> grid) {
    N = grid.size();
    M = grid[0].length();
    //그냥 dfs에 인수로 vector<string> 가지고다니기 싫었음
    //뭐가 더 오버헤드가 적을지는? 의문이네
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = grid[i][j];
        }
    }
    
    for(int i = 0; i<N; i++) {
        for(int j =0; j<M; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + didj[k][0];
                int nj = j + didj[k][1];
                if (ni < 0) ni = N - 1;
                else if (ni >= N) ni = 0;
                else if (nj < 0) nj = M - 1;
                else if (nj >= M) nj = 0;
                if((visit[ni][nj] & (1<<k))==0) dfs(i, j, k, ni, nj, k, 1);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}