#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
    public :
    int data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

bool uniValTreeHelper(BinaryTree* root, int *counter) {
    if(root == NULL)
        return false;
    if(root -> left == NULL && root -> right == NULL) {
        (*counter)++;
        return true;
    }
    if(uniValTreeHelper(root -> left, counter) && uniValTreeHelper(root -> right, counter)) {
        if(root-> left -> data == root -> right -> data)
            (*counter)++;
        return true;
    }
    return false;
}
int uniValTree(BinaryTree* root) {
    int counter = 0;
    uniValTreeHelper(root, &counter);
    return counter;
}

BinaryTree* takeInput() {
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    if(rootData == -1)
        return NULL;
    
    BinaryTree* root = new BinaryTree(rootData);
    BinaryTree* left = takeInput();
    BinaryTree* right = takeInput();

    root -> left = left;
    root -> right = right;

    return root;
}


int main() {
    BinaryTree* root = takeInput();
    cout << uniValTree(root) << endl;
    return 0;
}