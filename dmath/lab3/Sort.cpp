#include "Sort.h"
#include <iostream>

void show(vector<datatype>& arr,int start,int end){
    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;
}

void myswap(datatype &a, datatype &b){
    datatype temp = a;
    a = b;
    b = temp;
}

int MinItem(vector<datatype>& arr, int start, int end){
    int min_i = start;
    for(int i = start; i < end; i++){
        if(arr[min_i] > arr[i]){
            min_i = i;
        }
    }
    return min_i;
}

int MaxItem(vector<datatype>& arr, int start, int end){
    int max_i = start;
    for(int i = start; i < end; i++){
        if(arr[max_i] < arr[i]){
            max_i = i;
        }
    }
    return max_i;
}

void SortSelection(vector<datatype>& arr, int start, int end, int direction){
    if(direction == 0){
        for(int i = start; i < end; i++){
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