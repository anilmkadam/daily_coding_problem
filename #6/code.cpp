#include <iostream>
#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

class Node {
    public:
    int data;
    Node* both;

    Node(int data) {
        this -> data = data;
    }
};

Node* XOR(Node* a, Node* b) {
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insert(Node **HEAD, int data) {
    Node *newNode = new Node(data);
    if(*HEAD == NULL) {
        newNode -> both = XOR(*HEAD, NULL);
        *HEAD = newNode;
        return;
    }
    Node* current = *HEAD;
    Node *next, *prev = NULL;
    while(current != NULL) {
        next = XOR(prev, current -> both);
        prev = current;
        current = next;
    }
    newNode -> both = XOR(prev, NULL);
    prev -> both = XOR(prev -> both , newNode);

}

void get(Node* head, int index) {
    if(head == NULL) {
        cout << "Empty list." << endl;
        return;
    }
    if(index == 0) {
        cout << "Index should be greater than 0." << endl;
        return;
    }
    Node* current = head;
    Node *next, *prev = NULL;

    while(current != NULL && index > 0) {
        next = XOR(prev, current -> both);
        prev = current;
        current = next;
        index--;
    }
    if(index > 0)
        cout << "Index not exist." << endl;
    else 
        cout << prev -> data << endl;
}
void printList(Node *head) {
    Node* current = head;
    Node *next, *prev = NULL;

    while(current != NULL) {
        cout << current -> data << " -> ";
        next = XOR(prev, current -> both);
        prev = current;
        current = next;
    }
    cout << " null" << endl;
}

int main() {
    
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    get(head, 2);

    printList(head);
    return 0;
}