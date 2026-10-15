#include "List.h"
#include <iostream>
using namespace std;

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

void show_stack(Node* &head){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->key << " ";
        temp = temp->next;
    }
}

void enqueue(Queue* head, datatype key){
    Node* temp = new Node;
    temp->key = key;
    temp->next = nullptr;
    temp->previous = nullptr;
    if(head->front == nullptr){
        head->front = temp;
        head->rear = temp;
    }
    else{
        head->rear->next = temp;
        temp->previous = head->rear;
        head->rear = temp;
    }
    head->rear = temp;
}

void dequeue(Queue* head){
    if(head->front == nullptr or head == nullptr){
        return;
    }
    Node* temp = head->front;
    head->front = head->front->next;
    if(head->front != nullptr){
        head->front->previous = nullptr;
    }
    else{
        head->rear=nullptr;
    }
    delete temp;
}

void show_queue(Queue* head){
    if(head == nullptr){
        return;
    }
    Node* temp = head->front;
    while(temp != nullptr){
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}