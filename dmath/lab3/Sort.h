#include <vector>
using namespace std;

#ifndef SORT
#define SORT

typedef int datatype;

int MinItem(vector<datatype>& arr, int start = 0, int end = 0);
int MaxItem(vector<datatype>& arr, int start = 0, int end = 0);
void myswap(datatype &a, datatype &b);
void show(vector<datatype>& arr, int start = 0, int end = 0);
void SortSelection(vector<datatype>& arr, int start = 0, int end = 0, int direction = 0);

#endif