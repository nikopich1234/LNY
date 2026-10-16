#ifndef LIST
#define LIST

typedef int datatype;
struct Node;

void push(Node* &head, datatype key);
void pop(Node* &head);
void show(Node* &head);

void enqueue(Node* &front, Node* &rear, datatype val);
void dequeue(Node* &front);

void add_begin(Node* &first, Node* &last, datatype val);
void add_end(Node* &first, Node* &last, datatype val);
void del_begin(Node* &first, Node* &last);
void del_end(Node* &first, Node* &last);
Node* search(Node* &first, Node* &last, datatype val);
void add_mid(Node* &first, Node* &last, datatype val, datatype inval);
void del_mid(Node* &first, Node* &last, datatype val);


#endif