#include "Sort.h"


void myswap(datatype &a, datatype &b){
    datatype temp = a;
    a = b;
    b = temp;
}

datatype MinItem(vector<datatype> arr, int start, int end){
    datatype minitem = arr[0];
    for(int i = start; i < end; i++){
        if(minitem > arr[i]){
            minitem = i;
        }
    }
    return minitem;
}

datatype MaxItem(vector<datatype> arr, int start, int end){
    datatype maxitem = arr[0];
    for(int i = start; i < end; i++){
        if(maxitem < arr[i]){
            maxitem = i;
        }
    }
    return maxitem;
}

void SortSelection(vector<datatype> arr, int start, int end, int direction){
    if(direction == 0){
        for(int i = start; i <= end; i++){
            int min_i = MinItem(arr, i, end);
            if(min_i != i){
                myswap(arr[i], arr[min_i]);
            }
        }
    }
    else{
        for(int i = start; i < end; i++){
            int max_i = MaxItem(arr, i, end);
            if(max_i != i){
                myswap(arr[i], arr[max_i]);
            }
            
        }
    }
}