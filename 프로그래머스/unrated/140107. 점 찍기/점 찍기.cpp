#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long d_2 = d;
    d_2 *= d;
    
    for(int x = 0; x<=d; x+=k) {
        long long x_2 = x;
        x_2 *= x;
        long long y_max = floor(sqrt(d_2 - x_2));
        while (y_max % k!= 0) y_max--;
        answer += (y_max/k)+1;
    }
    
    return answer;
}