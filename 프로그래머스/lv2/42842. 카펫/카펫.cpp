#include <string>
#include <vector>

using namespace std;

int real_x, real_y;
void find_xy(int xy, int target) {
    //x와 y는 2 이상
    for(int x=2; xy-x>=2; x++) {
        int y = xy-x;
        if((x-2)*(y-2) == target) {
            real_x = x;
            real_y = y;
            break;
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x_plus_y = brown/2 + 2;
    find_xy(x_plus_y, yellow);
    if(real_x > real_y) {
        answer.push_back(real_x);
        answer.push_back(real_y);
    }
    else {
        answer.push_back(real_y);
        answer.push_back(real_x);
    }
    return answer;
}