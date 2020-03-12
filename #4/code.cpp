#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int segregateArray(int arr[], int size) {
    int j = 0, i;
    for(i = 0; i < size; i++) {
        if(arr[i] <= 0) {
            swap(&arr[i], &arr[j]);
            j++;
        }
    }
    return j;
}

int findingMissingPositiveNumHandler(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if((abs(arr[i]) - 1) < size && arr[abs(arr[i]) - 1] > 0)
             arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for(int i = 0; i < size; i++)
        if(arr[i] > 0)
            return i + 1;
    return size + 1;
}
int findingMissingPositiveNum(int arr[], int size) {
    int shift = segregateArray(arr, size);
    int missingNum = findingMissingPositiveNumHandler(arr + shift, size - shift);
}

int main() {
    int arr[] = { 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findingMissingPositiveNum(arr, size) << endl;
    return 0;
}


/*
    Following is the two step algorithm.
    1) Segregate positive numbers from others i.e., 
    move all non-positive numbers to left side. 
    In the following code, segregate() function does this part.
    2) Now we can ignore non-positive elements and consider only the part of array 
    which contains all positive elements. We traverse the array containing all positive numbers 
    and to mark presence of an element x, we change the sign of value at index x to negative. 
    We traverse the array again and print the first index which has positive value. 
    In the following code, findMissingPositive() function does this part.
*/
