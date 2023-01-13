#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string b:babbling) {
        bool is_okay = true;
        for(int i = 0; i<b.length(); i++) {
            if(b[i]=='a'){
                if(i+2 < b.length() && b[i+1] == 'y' && b[i+2] == 'a') {
                    i+=2;
                }
                else {
                    is_okay = false;
                    break;
                }
            }
            else if(b[i] == 'y') {
                if(i+1 < b.length() && b[i+1] == 'e') {
                    i++;
                }
                else {
                    is_okay = false;
                    break;
                }
            }
            else if(b[i] == 'w') {
                if(i+2 < b.length() && b[i+1] == 'o' && b[i+2] == 'o') {
                    i+=2;
                }
            }
            else if(b[i] == 'm') {
                if(i+1 < b.length() && b[i+1] == 'a') {
                    i++;
                }
                else {
                    is_okay = false;
                    break;
                }
            }
            else {
                is_okay = false;
                break;
            }
        }
        if(is_okay) answer++;
    }
    return answer;
}