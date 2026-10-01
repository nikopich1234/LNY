#include <iostream>
#include <vector>
using namespace std;

#ifndef SORT
#define SORT

typedef int datatype;

datatype MinItem(vector<datatype> arr, int start = 0, int end = 0);
datatype MaxItem(vector<datatype> arr, int start = 0, int end = 0);
void myswap(datatype &a, datatype &b);
void SortSelection(vector<datatype> arr, int start = 0, int end = 0, int direction = 0);

#endif