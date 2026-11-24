#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

struct Node;

void push(Node* &head, int key);
void show(Node* &head);
void pop(Node* &head);

#endif