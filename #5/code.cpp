#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class cons {
    public:
    cons() {}

    cons(T a, T b) {
        data.first = a;
        data.second = b;
    }
    public :
    pair<T, T> data;
    T car(cons);
    T cdr(cons);
};

template <typename T>
T cons<T> :: car(cons c) {
    return c.data.first;
}

template <typename T>
T cons<T> :: cdr(cons c) {
    return c.data.second;
}

int main() {
    cons<int> number;
    cout << number.car(cons<int>(3,4)) << endl;
    cout << number.cdr(cons<int>(3,4)) << endl;

    // cons<char> character;
    // cout << character.car(cons<char>('c','s')) << endl;
    // cout << character.cdr(cons<char>('c','s')) << endl;

    return 0;
}