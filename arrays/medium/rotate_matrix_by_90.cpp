#include<bits/stdc++.h>
using namespace std;


// ROTATE MATRIX BY 90 DEGREE (brute) |  TC - O(mn)  |  SC - O(mn)
// for square and rectangular matrix
// This approach uses a new matrix to store the rotated values.
void rotateMatrixBrute(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<int>> new_matrix(columns, vector<int>(rows));

    for(int m=0; m<rows; m++){
        for(int n=0; n<columns; n++){
            new_matrix[n][rows-m-1] = matrix[m][n];
        }
    }
    matrix = new_matrix;
}


// ROTATE MATRIX BY 90 DEGREE (optimal) |  TC - O(mn/2+mm/2) -> O(mn)  |  SC - O(1)
// only for square matrix
// This approach uses the concept of transposing the matrix and then reversing each row.
void rotateMatrixOptimal(vector<vector<int>> &matrix){
    // transpose the matrix
    int rows = matrix.size();
    int columns = matrix[0].size();

    for(int m=0; m<rows; m++){  // O(mn/2)
        for(int n=m; n<columns; n++){
            swap(matrix[m][n], matrix[n][m]);
        }
    }
    // reverse the matrix  |  O(mm/2)
    for(int m=0; m<rows; m++){
        reverse(matrix[m].begin(), matrix[m].end());
    }
}


int main(){
    return 0;
}