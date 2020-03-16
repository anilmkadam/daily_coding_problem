#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int length){
    int inclSum = arr[0];
    int exclSum = 0;
    int exclNew;
    for(int i = 1; i < length; i++) {
        exclNew = inclSum > exclSum ? inclSum : exclSum;
        inclSum = exclSum + arr[i];
        exclSum = exclNew;
    }
    return inclSum > exclSum ? inclSum : exclSum;
}

int main() {
    int arr[] = {5, 5, 10, 100, 10, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxSum(arr, length) << endl;
}