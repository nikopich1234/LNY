#ifndef LIST
#define LIST

typedef int datatype;
struct Node;
void push(Node* &head, datatype key);
void pop(Node* &head);
void show(Node* &head);

void enqueue(Node* &head, datatype key);
void dequeue(Node* &head);

#endif