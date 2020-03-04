#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input;
    vector<long int> product;
    int input_size;
    cin >> input_size;
    int temp;
    // first iteration calculating aux product
    long int aux_product = 1;
    for(int i = 0; i < input_size; ++i) {
        cin >> temp;
        input.push_back(temp);
        product.push_back(aux_product);
        aux_product *= temp;
    }

    //second iteration calculating final output
    aux_product = 1;
    for(int i = input_size - 1; i >= 0; --i) {
        product[i] = product[i] * aux_product;
        aux_product *= input[i];
    }
    //printing the output
    for (auto it = product.begin(); it != product.end(); ++it) 
        cout << *it << " ";
    return 0;
}