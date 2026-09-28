#include <iostream>
using namespace std;

#ifndef SORT
#define SORT

typedef double datatype;

int MinItem(datatype arr[], int start = 0, int end = 0);
int MaxItem(datatype arr[], int start = 0, int end = 0);
void show(datatype arr[], int start = 0, int end = 0);
void myswap(datatype &a, datatype &b);
void SortBubble(datatype arr[], int start = 0, int end = 0, int direction = 0);
void SortInsertion(datatype arr[], int start = 0, int end = 0, int direction = 0);
void SortSelection(datatype arr[], int start = 0, int end = 0, int direction = 0);

#endif