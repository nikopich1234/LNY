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
    Node* read = nullptr;
    
    cout << endl;


}