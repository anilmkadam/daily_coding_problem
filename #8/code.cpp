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
        return true;
    bool is_left_unival = uniValTreeHelper(root -> left, counter);
    bool is_right_unival = uniValTreeHelper(root -> right, counter);

    if(is_left_unival && is_right_unival) {
        if(root-> left != NULL && root -> data != root -> left -> data)
            return false;
        if(root-> right != NULL && root -> data != root -> right -> data)
            return false;
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