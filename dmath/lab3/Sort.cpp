#include "Sort.h"


void myswap(datatype &a, datatype &b){
    datatype temp = a;
    a = b;
    b = temp;
}

void show(datatype arr[], int start, int end){
    for(int i = start; i < end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

datatype MinItem(datatype arr[], int start, int end){
    datatype minitem = arr[0];
    for(int i = start; i < end; i++){
        if(minitem > arr[i]){
            minitem = i;
        }
    }
    return minitem;
}

datatype MaxItem(datatype arr[], int start, int end){
    datatype maxitem = arr[0];
    for(int i = start; i < end; i++){
        if(maxitem < arr[i]){
            maxitem = i;
        }
    }
    return maxitem;
}

void SortBubble(datatype arr[], int start, int end){
    for(int i = start; i < end; i++){
        bool swapped = false;
        for(int j = start; j < end-1; j++){
            if(arr[j] > arr[j+1]){
                myswap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(not swapped){
            break;
        }
    }
}

void SortInsertion(datatype arr[], int start, int end){
    for(int i = start+1; i < end; i++){
        datatype temp = arr[i];
        int index = i - 1;
        while(index >= start && arr[index] > temp){
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = temp;
        
    }
}

void SortSelection(datatype arr[], int start, int end){
    for(int i = start; i < end; i++){
        int min = i;
        for(int j = i + 1; j < end; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        myswap(arr[i],arr[min]);
    }
}