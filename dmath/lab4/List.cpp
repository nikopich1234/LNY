#include "List.h"

struct Node{
    datatype key;
    Node* next;
};

void push(Node* &head, int key){
    Node *temp = new Node;
    temp->key = key;
    temp->next = head;
    head = temp;
}

void pop(Node* &head){
    if(head == nullptr){
        return;
    }
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void show(Node* &head){
    Node *temp = head;
    
}