#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans_g;
bool used[10000];

int gh_cnt = 0;
void dfs(string here, int cnt, vector<string> ans, vector<vector<string>> tickets) {
    if (cnt == tickets.size() && ans_g.empty()) {
        ans_g = ans;
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == here && !used[i]) {
            string gh = tickets[i][1];
            vector<string> tmp(ans);
            tmp.push_back(gh);
            used[i] = true;
            dfs(gh, cnt + 1, tmp, tickets);
            used[i] = false;
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    dfs("ICN", 0, { "ICN" }, tickets);
    answer = ans_g;
    return answer;
}