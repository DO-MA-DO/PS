#include <string>
#include <vector>
#include <queue>

using namespace std;

struct info{
    int i, j, cnt;
};

bool map[102][102];
bool visit[102][102];
int didj[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int si, int sj, int ti, int tj) {
    queue<info> q;
    q.push({si, sj, 0});
    visit[si][sj] = true;
    
    while(!q.empty()) {
        info h = q.front();
        q.pop();
        int hi = h.i;
        int hj = h.j;
        int cnt = h.cnt;
        
        if(hi == ti && hj == tj) return cnt;
        
        for(int k = 0; k<4; k++) {
            int ni = hi + didj[k][0];
            int nj = hj + didj[k][1];
            if(!map[ni][nj] || visit[ni][nj]) continue;
            visit[ni][nj] = true;
            q.push({ni, nj, cnt+1});
        }
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    //fill black
    for(int i = 0; i<rectangle.size(); i++) {
        int min_x = rectangle[i][0]*2;
        int min_y = rectangle[i][1]*2;
        int max_x = rectangle[i][2]*2;
        int max_y = rectangle[i][3]*2;
        for(int x = min_x; x<=max_x; x++) {
            for(int y = min_y; y<=max_y; y++) {
                map[x][y] = true;
            }
        }
    }
    //fill white
    for(int i = 0; i<rectangle.size(); i++) {
        int min_x = rectangle[i][0]*2 + 1;
        int min_y = rectangle[i][1]*2 + 1;
        int max_x = rectangle[i][2]*2 - 1;
        int max_y = rectangle[i][3]*2 - 1;
        for(int x = min_x; x<=max_x; x++) {
            for(int y = min_y; y<=max_y; y++) {
                map[x][y] = false;
            }
        }
    }
    answer = bfs(characterX*2, characterY*2, itemX*2, itemY*2)/2;
    return answer;
}