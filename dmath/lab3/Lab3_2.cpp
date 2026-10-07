#include "Sort.h"
#include "Comb.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    vector<int> arr;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        arr.push_back(i+1);
    }

    for(auto item : arr){
        cout << item << " ";
    }

    cout << endl;

    ofstream writer;
    writer.open("C:\\Users\\nikop\\OneDrive\\Desktop\\LNY\\LNY\\dmath\\lab3\\Lab3_2_Permutations");
    if(writer.is_open()){
        for(int i = 0; i < factorial(size); i++){
            writer << "№" << i+1 << " | ";
            for(auto x : arr){
                writer << x << " ";
            }
            writer << "\n";
            GenPerm(arr, 0, size);
        }
    }
    writer.close();

    int n,k;
    vector<datatype>nums;
    cin >> n >> k;
    
    for(int i = 0; i < k; i++){
        nums.push_back(i+1);
    }

    writer.open("C:\\Users\\nikop\\OneDrive\\Desktop\\LNY\\LNY\\dmath\\lab3\\Lab3_2_Combinations");
    if(writer.is_open()){
        for(int i = 0; i < C(n,k);i++){
            writer << "№" << i+1 << " | ";
            for(auto x: nums){
                writer << x << " ";
            }
            writer << "\n";
            GenComb(nums,0,k,n,k);
        }
    }
    writer.close();

    cout << endl;
}