#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string.h>
using namespace std;

class StringParser {
    void stringToFileDir(string path) {
    }
};

int main() {
    string path {"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"};
    //std::replace(path.begin(), path.end(), "\n","@");

    cout << path;
}