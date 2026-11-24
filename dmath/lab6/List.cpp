#include "List.h"

struct Node{
    int key;
    Node* next;
};

void push(Node* &head, int key){
    Node* temp = new Node;
    temp->key = key;
    temp->next = head;
    head = temp;
}

void pop(Node* &head){
    if(head != nullptr){
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
}

int show(Node* &head){
    return head->key;
}