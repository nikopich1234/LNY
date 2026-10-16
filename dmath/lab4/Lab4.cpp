#include "List.h"
#include <iostream>
using namespace std;

int main(){
    Node* stack = nullptr;
    push(stack,5);
    show(stack);
    cout << endl;
    push(stack,10);
    show(stack);
    cout << endl;
    pop(stack);
    show(stack);
    cout << endl;
    pop(stack);
    show(stack);
    cout << endl;

    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, 5);
    show(front);
    cout << endl;
    enqueue(front, rear, 10);
    show(front);
    cout << endl;
    dequeue(front);
    show(front);
    cout << endl;
    dequeue(front);
    show(front);
    cout << endl;
    dequeue(front);
    show(front);
    cout << endl;

    Node* first = nullptr;
    Node* last = nullptr;
    add_begin(first,last,10);
    show(first);
    cout << endl;
    add_begin(first,last,20);
    show(first);
    cout << endl;
    add_end(first,last,30);
    show(first);
    cout << endl;
    add_mid(first,last,30, 40);
    show(first);
    cout << endl;
    del_end(first,last);
    show(first);
    cout << endl;
    del_begin(first,last);
    show(first);
    cout << endl;
    del_mid(first,last,20);
    show(first);
    cout << endl;
    del_mid(first,last,10);
    show(first);
    cout << endl;
}