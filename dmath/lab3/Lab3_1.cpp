#include "Comb.h"
#include "Sort.h"
#include <vector>
#include <cstdlib>
#include <ctime>

int main(){

    srand(time(NULL));

    int n,k;
    cin >> n >> k;
    cout << "factorial n: " << factorial(n) << endl << "factorial k: " << factorial(k) << endl << "A(n,k): " << A(n,k) << endl << "_A(n,k): " << _A(n,k) << endl << "C(n,k): " << C(n,k) << endl << "_C(n,k): " << _C(n,k) << endl;
    
    vector<int> arr;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        arr.push_back(rand()%101);
    }
    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;

    SortSelection(arr, 0, size, 0);

    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;

    GenPerm(arr, size, 0);

    cout << endl;
}