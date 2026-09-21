#include "Sort.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;


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
        arr[i] = rand() % 1001;
    }
    
    datatype* new_arr = new datatype[size];
    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }

    show(arr, start, end);

    auto time_start = high_resolution_clock::now();
    SortBubble(new_arr, start, end);
    auto time_end = high_resolution_clock::now();
    auto elapsed = duration<double, nano>(time_end - time_start);
    cout << "sorted array (Bubble sort):" << endl;
    show(new_arr, start, end);
    cout << "time in nanoseconds: " << elapsed.count() << endl;

    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }
    time_start = high_resolution_clock::now();
    SortSelection(new_arr, start, end);
    time_end = high_resolution_clock::now();
    elapsed = duration<double, nano>(time_end - time_start);
    cout << "sorted array (Selection sort):" << endl;
    show(new_arr, start, end);
    cout << "time in nanoseconds: " << elapsed.count() << endl;

    for(int i = 0; i < size; i++){
        new_arr[i] = arr[i];
    }
    time_start = high_resolution_clock::now();
    SortInsertion(new_arr, start, end);
    time_end = high_resolution_clock::now();
    elapsed = duration<double, nano>(time_end - time_start);
    cout << "sorted array (Insertion sort):"  << endl;
    show(new_arr, start, end);
    cout << "time in nanoseconds: " << elapsed.count() << endl;

    delete[] arr;
    delete[] new_arr;

    return 0;
}