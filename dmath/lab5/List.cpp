#include "List.h"

struct Node{
    datatype key;
    Node* next;
};


void push(Node* &head, datatype key){
    Node *temp = new Node;
    temp->key = key;
    temp->next = head;
    head = temp;
}

void pop(Node* &head){
    if(head == nullptr){
        cout << "Stack is empty\n";
        return;
    }
    Node *temp = head;
    head = temp->next;
    delete temp;
}

datatype show(Node* &head){
    if(head != nullptr){
        Node *temp = head;
        return temp->key;
    }
    throw runtime_error("Stack is empty");
}

int size(Node* &head){
    int counter = 0;
    Node* temp = head;
    while(temp != nullptr){
        counter++;
        temp = temp->next;
    }
    return counter;
}