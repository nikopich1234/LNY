#include "List.h"

int main(){

    int n = 8;

    Node* stack = nullptr;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));

    vector<pair<int, int>> edges = {
        {1,2}, {1,3}, {1,4}, {1,7}, {1,8},
        {2,7}, {2,8}, {7,8},
        {4,5}, {4,6}, {5,6}
    };

    for (auto& e : edges){
        matrix[e.first][e.second] = 1;
        matrix[e.second][e.first] = 1;
    }

    cout << "Matrix:\n";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // DFS non-recursion
    vector<bool> visited;
    vector<int> dfsnumber;
    int start = 1;
    int number = 1;
    visited[start] = true;
    dfsnumber[start] = number;
    push(start);

    while(stack != nullptr){
        for(int i = 1; i <= n; i++){
            if(visited[matrix[show(stack)][i]] == false && martix[show(stack)][i] == 1){
                number++;;
                visited[matrix[show(stack)][i]] = true;
                dfsnumber[i] = number;
                break;
            }
            else{
                pop(stack);
            }
        }
    }

    return 0;
}