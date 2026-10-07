#include "Sort.h"
#include "Comb.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    vector<int> arr1;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        arr1.push_back(i+1);
    }

    for(auto item : arr1){
        cout << item << " ";
    }

    cout << endl;

    ofstream writer;
    writer.open("C:\\Users\\nikop\\OneDrive\\Desktop\\LNY\\LNY\\dmath\\lab3\\Lab3_2_Permutations");
    if(writer.is_open()){
        for(int i = 0; i < factorial(size); i++){
            writer << "№" << i+1 << " | ";
            for(auto x : arr1){
                writer << x << " ";
            }
            writer << "\n";
            GenPerm(arr1, 0, size);
        }
    }
    writer.close();

    int n,k;
    vector<datatype>arr2;
    cin >> n >> k;
    
    for(int i = 0; i < k; i++){
        arr2.push_back(i+1);
    }

    writer.open("C:\\Users\\nikop\\OneDrive\\Desktop\\LNY\\LNY\\dmath\\lab3\\Lab3_2_Combinations");
    if(writer.is_open()){
        for(int i = 0; i < C(n,k);i++){
            writer << "№" << i+1 << " | ";
            for(auto x: arr2){
                writer << x << " ";
            }
            writer << "\n";
            GenComb(arr2,0,k,n,k);
        }
    }
    writer.close();

    vector<datatype> arr3;

    for(int i = 0; i < size; i++){
        arr3.push_back(i+1);
    }

    cout << endl;

    GenArr(arr3, n,k);
}