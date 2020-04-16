#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

void deleteNThNodeFromLast(Node** head, int n) {
    Node* ptr1 = *head;
    Node* ptr2 = *head;
    Node* prev = *head;
    
    while(n > 0) {
        ptr1 = ptr1 -> next;
        --n;
    }
    while(ptr1 != NULL) {
        prev = ptr2;
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    if(prev == *head) {
        *head = ptr2 -> next;
        free(ptr2);
        return;
    }
    prev -> next = ptr2 -> next;
    free(ptr2);
}

void insertNode(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if(*head == NULL) {
        *head = newNode;
        newNode -> next = NULL;
        return;
    }
    Node* current = *head;
    Node* prev = current;
    while(current != NULL) {
        prev = current;
        current = current -> next;
    }
    newNode -> next = current;
    prev -> next = newNode;
}

void printList(Node* head) {
    if(head == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    printList(head);

    deleteNThNodeFromLast(&head, 5);

    printList(head);
    return 0;
}