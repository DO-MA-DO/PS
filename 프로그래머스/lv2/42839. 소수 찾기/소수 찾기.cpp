#include <string>
#include <vector>

using namespace std;
bool is_prime[10000000];
bool check[10000000];
bool is_in[7];
int ans = 0;

void count_prime(string numbers, string num) {
    if(num.length() > numbers.length()) return;
    if(num.length() >= 1) {
        //printf("%d\n", stoi(num));
        if(is_prime[stoi(num)] && !check[stoi(num)]) {
            check[stoi(num)] = true;
            ans++;
            //printf("-->ans++\n");
        }
    }
    
    
    for(int i = 0; i<numbers.size(); i++) {
        if(is_in[i]) continue;
        is_in[i] = true;
        string tmp(num);
        tmp += numbers.substr(i, 1);
        count_prime(numbers, tmp);
        is_in[i] = false;
    }
}


int solution(string numbers) {
    int answer = 0;
    for(int i = 2; i<10000000; i++) {
        is_prime[i] = true;
    }
    for(int i = 2; i<10000000; i++) {
        if(!is_prime[i]) continue;
        for(int j = 2*i; j<10000000; j += i) {
            is_prime[j] = false;
        }
    }
    
    count_prime(numbers, "");
    answer = ans;
    return answer;
}