#include <iostream>
#include <bits/stdc++.h>
#define MAX 100

using namespace std;

int getMinMeetingRoom(int timings[][2], int n) {
    int prefix_sum[MAX] = {0};

    for(int i = 0; i < n; i++) {
        prefix_sum[timings[i][0]]++;
        prefix_sum[timings[i][1] + 1]--;
    }
    int ans = prefix_sum[0];
    for(int i = 1; i < MAX; i++) {
        prefix_sum[i] += prefix_sum[i-1];
        ans = max(ans, prefix_sum[i]);
    }
    return ans;
}

int main() {
    // [(30, 75), (0, 50), (60, 150)]
    int timings[][2] = {{30, 75}, {0, 50}, {60, 150}};
    int size = sizeof(timings) / sizeof(timings[0]);
    cout << getMinMeetingRoom(timings, size) << endl;
    return 0;
}