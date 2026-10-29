#include "List.h"
#include <iostream>
using namespace std;

int main(){
    cout << "stack:\n";
    Node* stack = nullptr;
    push(stack,5);
    show(stack);
    push(stack,10);
    show(stack);
    pop(stack);
    show(stack);
    pop(stack);
    show(stack);
    pop(stack);
    show(stack);

    Node* front = nullptr;
    Node* rear = nullptr;
    
    cout << "queue:\n";
    enqueue(front, rear, 5);
    show(front);
    enqueue(front, rear, 10);
    show(front);
    dequeue(front);
    show(front);
    dequeue(front);
    show(front);;
    dequeue(front);
    show(front);

    Node* first = nullptr;
    Node* last = nullptr;
    cout << "deque:\n";
    add_begin(first,last,10);
    show(first);
    add_begin(first,last,20);
    show(first);
    add_end(first,last,30);
    show(first);
    add_mid(first,last,10, 40);
    show(first);
    del_end(first,last);
    show(first);
    del_begin(first,last);
    show(first);
    del_mid(first,last,20);
    show(first);
    del_mid(first,last,10);
    show(first);
}