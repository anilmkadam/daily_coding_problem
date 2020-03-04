#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input;
    int input_size;
    cin >> input_size;
    int temp;
    long int total_product = 1;
    for(int i = 0; i < input_size; i++) {
        cin >> temp;
        input.push_back(temp);
        total_product *= temp;
    }
    for(int i = 0; i < input.size(); i++) {
        cout << total_product / input[i] << " ";
    }
    return 0;
}