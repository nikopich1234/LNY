#include <iostream>
#include "LogCon.h"
using namespace std;

int main(){

    for(int i = 0; i < 61; i++){
    cout << "-";
    }
    cout << endl;

    cout << "a" << "\t" << "b" << "\t" << "NOT(a)" << "\t" << "AND" << "\t" <<  "OR" << "\t" << "IMP" << "\t" << "EQU" << "\t" << "XOR" << "\t" << endl;

    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            
            cout << i << "\t" << j << "\t" << NOT(i) << "\t" << AND(i,j) << "\t" << OR(i,j) << "\t" << IMP(i,j) << "\t" << EQU(i,j) << "\t" << XOR(i,j) << endl;
        }
    }

    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;

    cout << "Function 15" << endl;

    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;

    cout << "a" << "\t" << "b" << "\t" << "c" << "\t" << "res" << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){

                cout << i << "\t" << j << "\t" << k << "\t" << F15(i,j,k) << endl;
            }
        }
    }
    
    for(int i = 0; i < 61; i++){
        cout << "-";
    }
    cout << endl;

    return 0;
}