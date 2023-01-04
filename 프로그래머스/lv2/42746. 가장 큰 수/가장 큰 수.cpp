#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const string &str1, const string &str2) {
    string s1(str1);
    string s2(str2);
    int i = 0;
    while(s1.length() != 4) {
        s1 += s1[i++];
    }
    i=0;
    while(s2.length() != 4) {
        s2 += s2[i++];
    }
    int a = stoi(s1);
    int b = stoi(s2);
    return a>b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    bool all_zero = true;
    for(int n:numbers) {
        if(n != 0) all_zero = false;
        strs.push_back(to_string(n));
    }
    if(all_zero) answer = "0";
    else {
        sort(strs.begin(), strs.end(), cmp);
        for(string s: strs) {
            answer += s;
        }
    }
    return answer;
}