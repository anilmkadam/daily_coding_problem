#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int calculateSteps(int step, vector<int> climb_step) {
    if(step == 0)
        return 1;
    vector<int> possible_ways;
    possible_ways.push_back(1);
    for(int i = 1; i <= step; i++) {
        int total = 0;
        for(int j = 0; j < climb_step.size(); j++) {
            if( i - climb_step[j] >= 0)
                total += possible_ways[i - climb_step[j]];
        }
        possible_ways[i] = total;
    }
    return possible_ways[step];
}

int main() {
    int step, x, num;
    cout << "enter steps" << endl;
    cin >> step;
    cout << "enter x" << endl;
    cin >> x;
    
    vector<int> climb_step;
    cout << "enter step size" << endl;
    for(int i = 0; i < x; i++) {
        cin >> num;
        climb_step.push_back(num);
    }
    int total = calculateSteps(step, climb_step);
    cout << total << endl;
    return 0;
}