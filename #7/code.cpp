#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int decodeHelper(string data, int k) {
    if(k == 0)
        return 1;
    int start = data.length() - k;
    if(data[start] == '0')
        return 0;
    int result = decodeHelper(data, k-1);
    if(k >=2 && (data.substr(start, 2)) <= "26")
        result += decodeHelper(data, k-2);
    return result;
}

int decodeHelperDP(string data, int k, int memo[]) {
    if(k == 0 || k == 1)
        return 1;
    int start = data.length() - k;
    if(data[start] == '0')
        return 0;
    if(memo[k] != 0)
        return memo[k];
    int result = decodeHelperDP(data, k-1, memo);
    if(k >=2 && (data.substr(start, 2)) <= "26")
        result += decodeHelperDP(data, k-2,memo);
    memo[k] = result;
    return result;
}

int decode(string msg) {
    // return decodeHelper(msg, msg.length());
    // By using dynamic programming
    int previous_state[msg.length()];
    return decodeHelperDP(msg, msg.length(), previous_state);
}
int main() {
    string msg = "1";
    cout << decode(msg) << endl;
}