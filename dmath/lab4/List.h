#ifndef LIST
#define LIST

typedef int datatype;
struct Node{
    datatype key;
    Node* next;
    Node* previous;
};

struct Queue{
    Node* front = nullptr;
    Node* rear = nullptr;
};
void push(Node* &head, datatype key);
void pop(Node* &head);
void show_stack(Node* &head);

void enqueue(Queue* head, datatype key);
void dequeue(Queue* head);
void show_queue(Queue* head);

#endif