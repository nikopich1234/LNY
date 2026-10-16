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
        cout << "Stack is empty";
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

void enqueue(Node* &front, Node* &rear, datatype val){
    Node* temp = new Node;
    temp->key = val;
    temp->next = nullptr;
    if(front == nullptr){
        cout << "Queue is empty";
        front = temp;
    }
    else{
        rear->next = temp;
    }
    rear = temp;
}

void dequeue(Node* &front){
    if(front == nullptr){
        return;
    }
    Node* temp = front;
    front = temp->next;
    delete temp;
}

void add_begin(Node* &first, Node* &last, datatype val){
    Node* temp = new Node;
    temp->key = val;
    temp->next = first;
    temp->previous = nullptr;
    if(first != nullptr){
        first->previous = temp;
    }
    else{
        last = temp;
    }
    first = temp;
}
void add_end(Node* &first, Node* &last, datatype val){
    Node* temp = new Node;
    temp->key = val;
    temp->next = nullptr;
    temp->previous = last;
    if(last != nullptr){
        last->next = temp;
    }
    else{
        first = temp;
    }
    last = temp;
}

void del_begin(Node* &first, Node* &last){
    if(first == nullptr){
        cout << "List is empty";
        return;
    }
    Node* temp = first;
    first = temp->next;
    if(first->previous != nullptr){
        first->previous = nullptr;
    }
    else{
        last = nullptr;
    }
    delete temp;
}

void del_end(Node* &first, Node* &last){
    if(last == nullptr){
        cout << "List is empty";
        return;
    }

    Node* temp = last;
    last = temp->previous;
    if(last->next != nullptr){
        last->next = nullptr;
    }
    else{
        first = nullptr;
    }
    delete temp;
}

Node* search(Node* &first, Node* &last, datatype val){
    Node* temp = first;
    while(temp != nullptr){
        if(temp->key == val){
            return(temp);
        }
        else{
            temp = temp->next;
        }
    }
    cout << "There is no such value in list " << val;
    cout << endl;
    return nullptr;
}

void add_mid(Node* &first, Node* &last, datatype val, datatype inval){
    if(search(first, last, val) == nullptr){
        return;
    }
    else if(search(first,last,val) == last){
        add_end(first, last,inval);
        return;
    }
    Node* pkey = search(first,last,val);
    Node* temp = new Node;
    temp->key = inval;
    temp->next = pkey->next;
    temp->previous = pkey;
    pkey->next = temp;
    (temp->next)->previous = temp;
}

void del_mid(Node* &first, Node* &last, datatype val){
    if(search(first,last,val) == nullptr){
        return;
    }
    else if(search(first,last,val) == first){
        del_begin(first,last);
        return;
    }
    else if(search(first,last,val) == last){
        del_end(first,last);
        return;
    }
    Node* pkey = search(first,last,val);
    (pkey->previous)->next = pkey->next;
    (pkey->next)->previous = pkey->previous;
    delete pkey;
}