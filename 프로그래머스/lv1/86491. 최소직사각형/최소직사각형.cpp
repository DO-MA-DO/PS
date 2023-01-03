#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(int i = 0; i<sizes.size(); i++) {
        if(sizes[i][0] > sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
    }
    int mw = 0;
    int mh = 0;
    for(int i = 0; i<sizes.size(); i++) {
        mw = max(mw, sizes[i][0]);
        mh = max(mh, sizes[i][1]);
    }
    answer = mw*mh;
    return answer;
}