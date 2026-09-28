#include <iostream>
#include <vector>
using namespace std;

#ifndef SORT
#define SORT

typedef int datatype;

datatype MinItem(datatype arr[], int start = 0, int end = 0);
datatype MaxItem(datatype arr[], int start = 0, int end = 0);
void show(datatype arr[], int start = 0, int end = 0);
void myswap(datatype &a, datatype &b);
void SortBubble(vector<datatype> nums, int start = 0, int end = 0);
void SortInsertion(vector<datatype> nums, int start = 0, int end = 0);
void SortSelection(vector<datatype> nums, int start = 0, int end = 0);

#endif