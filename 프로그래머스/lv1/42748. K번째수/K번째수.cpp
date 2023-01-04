#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i<commands.size(); i++) {
        vector<int> tmp(array);
        int s = commands[i][0]-1;
        int e = commands[i][1];
        int p = commands[i][2]-1;
        
        sort(tmp.begin() + s, tmp.begin() + e);
        answer.push_back(tmp[s+p]);
    }
    
    return answer;
}