#include "List.h"
#include <iostream>
using namespace std;

int main(){
    Node* stack = nullptr;
    push(stack,5);
    show_stack(stack);
    cout << endl;
    push(stack,10);
    show_stack(stack);
    cout << endl;
    pop(stack);
    show_stack(stack);
    cout << endl;
    pop(stack);
    show_stack(stack);
    cout << endl;

    Queue* myqueue = new Queue();
    for(int i = 1; i < 3; i++){
        enqueue(myqueue, i);
        show_queue(myqueue);
    }

    for(int i = 1; i < 3; i++){
        dequeue(myqueue);
        show_queue(myqueue);
    }


}