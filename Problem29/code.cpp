#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void encodedString(string str) {
    int len = str.length();
    for(int i = 0; i < len; i++) {
        int count = 1;
        while (i < len-1 && str[i] == str[i+1])
        {
            count++;
            i++;
        }
        cout << count << str[i];
    }
    cout << endl;
}

int main() {
    string str = "wadex";
    encodedString(str);
    return 0;
}

/*
    input 1: "AAAABBBCCDAA"
    o/p : 4A3B2C1D2A "4A3B2C1D2A".

    input 2: "wwwwaaadexxxxxx"
    o/p : 4w3a1d1e6x "w4a3d1e1x6".
*/