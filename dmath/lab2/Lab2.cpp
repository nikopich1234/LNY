#include "Sort.h"
#include <cstdlib>
#include <ctime>


int main(){
    srand(time(NULL));
    int size, start, end;
    cin >> size >> start >> end;
    datatype* arr = new datatype[size];

    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;
    cout << "Random array:" << endl;

    for(int i = 0; i < size; i++){
        arr[i] = rand() % 11;
    }
    show(arr,start, end);
    cout << "Sorted array (Bubble sort):" << endl;
    SortBubble(arr, start, end);
    show(arr, start, end);
    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;


    for(int i = 0; i < size; i++){
        arr[i] = rand() % 11;
    }
    cout << "Random array:" << endl;
    show(arr, start, end);
    cout << "Sorted array (Selection sort):" << endl;
    SortSelection(arr, start, end);
    show(arr, start, end);
    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;
    
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 11;
    }
    cout << "Random array:" << endl;
    show(arr,start,end);
    cout << "Sorted array (Insertoin sort):" << endl;
    SortInsertion(arr,start,end);
    show(arr,start,end);
    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;

    delete[] arr;

    return 0;
}