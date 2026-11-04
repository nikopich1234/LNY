#include <iostream>
#include <string>
using namespace std;

#ifndef List
#define List

typedef string datatype;
struct Node;

void push(Node* &head, datatype key);
void pop(Node* &head);
datatype show(Node* &head);
int size(Node* &head);

#endif