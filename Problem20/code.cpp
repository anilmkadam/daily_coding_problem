#include <iostream>
#include <bits/stdc++.h>
#include "NODE.h"
using namespace std;

class LinkedList {
    Node* head = NULL;
    public :
    void insert(int data) {
        Node* newNode = new Node();
        newNode -> data = data;
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while(current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
        return;
    }
    void display() {
        Node* current = head;
        if(head == NULL) {
            cout << "EMPTY LIST" << endl;
            return;
        }
        while (current != NULL) {
            cout << current->data << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);
    LinkedList ll;
    for(int i = 0; i < size; i++) {
        ll.insert(arr[i]);
    }
    ll.display();
    return 0;
}