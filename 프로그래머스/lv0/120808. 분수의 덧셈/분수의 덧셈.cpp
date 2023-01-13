#include <string>
#include <vector>

using namespace std;
//오버플로 안남
int find_gcd(int a, int b) {
    if(a%b == 0) return b;
    return find_gcd(b, a%b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int gcd = 0;
    if(denom1 > denom2) gcd = find_gcd(denom1, denom2);
    else gcd = find_gcd(denom2, denom1);
    int lcm = (denom1*denom2)/gcd;

    int num_sum = (lcm/denom1)*numer1 + (lcm/denom2)*numer2;
    int gcd2 = find_gcd(num_sum, lcm);
    if(gcd2 != 1) {
        num_sum /= gcd2;
        lcm /= gcd2;
    }
    answer.push_back(num_sum);
    answer.push_back(lcm);
    return answer;
}