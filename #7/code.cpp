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

int decode(string msg) {
    return decodeHelper(msg, msg.length());
}
int main() {
    string msg = "11111";
    cout << decode(msg) << endl;
}