#include "Sort.h"


void myswap(datatype &a, datatype &b){
    datatype temp = a;
    a = b;
    b = temp;
}

void show(datatype arr[], int start, int end){
    for(int i = start; i <= end; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int MinItem(datatype arr[], int start, int end){
    int minitem = start;
    for(int i = start+1; i <= end; i++){
        if(arr[minitem] > arr[i]){
            minitem = i;
        }
    }
    return minitem;
}

int MaxItem(datatype arr[], int start, int end){
    int maxitem = start;
    for(int i = start+1; i <= end; i++){
        if(arr[maxitem] < arr[i]){
            maxitem = i;
        }
    }
    return maxitem;
}

void SortBubble(datatype arr[], int start, int end, int direction){
    if(direction == 0){
        for(int i = start; i <= end; i++){
            bool swapped = false;
            for(int j = start; j < end; j++){
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
    else{
        for(int i = start; i <= end; i++){
            bool swapped = false;
            for(int j = start; j < end; j++){
                if(arr[j] < arr[j+1]){
                    myswap(arr[j],arr[j+1]);
                    swapped = true;
                }
            }
            if(not swapped){
                break;
            }
        }
    }
}

void SortInsertion(datatype arr[], int start, int end, int direction){
    if(direction == 0){
        for(int i = start+1; i <= end; i++){
            datatype temp = arr[i];
            int index = i - 1;
            while(index >= start && arr[index] > temp){
                arr[index+1] = arr[index];
                index--;
            }
            arr[index+1] = temp;
            
        }
    }
    else{
        for(int i = start+1; i <= end; i++){
            datatype temp = arr[i];
            int index = i - 1;
            while(index >= start && arr[index] < temp){
                arr[index+1] = arr[index];
                index--;
            }
            arr[index+1] = temp;
            
        }
    }
}

void SortSelection(datatype arr[], int start, int end, int direction){
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