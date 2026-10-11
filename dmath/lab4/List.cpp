#include "List.h"
#include <iostream>
using namespace std;

struct Node{
    datatype key;
    Node* next;
    Node* previous;
};

void push(Node* &head, datatype key){
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
    while(temp != nullptr){
        cout << temp->key << " ";
        temp = temp->next;
    }
}

void enqueue(Node* &head, datatype key){
    Node* front = nullptr;
    Node* rear = nullptr;
    Node* temp = new Node;
    temp->key = key;
    temp->next = nullptr;
    if(head == nullptr){
        front = temp;
    }
    else{
        rear->next = temp;
    }
    rear = temp;
}

void dequeue(Node* &head){
    if(head == nullptr){
        return;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
}