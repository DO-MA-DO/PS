#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[1000];
vector<pair<int, int>> ans;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second > p2.second;
}

int solution(vector<int> array) {
    int answer = 0;
    for(int a: array) {
        cnt[a]++;
    }
    for(int i = 0; i<1000; i++) {
        if(cnt[i] != 0) {
            ans.push_back({i, cnt[i]});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if(ans.size()>1 && ans[0].second == ans[1].second) answer = -1;
    else answer = ans[0].first;
    
    return answer;
}