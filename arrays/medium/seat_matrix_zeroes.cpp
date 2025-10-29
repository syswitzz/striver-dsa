#include<bits/stdc++.h>
using namespace std;


// SEAT MATRIX ZEROES (brute)  |  TC - O(mn(m+n+1)) where m=rows, n=columns
// basically wherever in the matrix there is zero then make its rows and columns also zero
void makeRowZero(vector<vector<int>> &matrix, int i){
    int columns = matrix[0].size();
    for(int j=0; j<columns; j++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
void makeColumnZero(vector<vector<int>> &matrix, int j){
    int rows = matrix.size();
    for(int i=0; i<rows; i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}
void seatMatrixBrute(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j]==0){
                makeRowZero(matrix, i);
                makeColumnZero(matrix, j);
            }
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=0;
            }
        }
    }
}


// SEAT MATRIX ZEROES (better)  |  TC - O(2mn) where m=rows, n=columns  |  SC - O(m+n)
void seatMatrixBetter(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();

    vector<int> row_vector(rows, 0);
    vector<int> column_vector(columns, 0);

    for(int m=0; m<rows; m++){
        for(int n=0; n<columns; n++){
            if(matrix[m][n]==0){
                row_vector[m]=1;
                column_vector[n]=1;
            }
        }
    }
    for(int m=0; m<rows; m++){
        for(int n=0; n<columns; n++){
            if(row_vector[m]==1 || column_vector[n]==1){
                matrix[m][n]=0;
            }
        }
    }
}


// SEAT MATRIX ZEROES (optimal)  |  TC - O(2mn) where m=rows, n=columns  |  SC - O(1)
void seatMatrixOptimal(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    int temp = 1;

    for(int m=0; m<rows; m++){
        for(int n=0; n<columns; n++){
            if(matrix[m][n]==0){
                matrix[m][0]=0;
                if(n==0) temp=0;
                else matrix[0][n]=0;
            }
        }
    }
    for(int m=1; m<rows; m++){
        for(int n=1; n<columns; n++){
            if(matrix[m][0]==0 || matrix[0][n]==0){
                matrix[m][n]=0;
            }
        }
    }
    // Check first ROW before zeroing first COLUMN
    if(matrix[0][0]==0){
        for(int n =0; n< columns; n++){
            matrix[0][n] = 0;
        }
    }
    if(temp==0){
        for (int m= 0; m < rows; m++){
            matrix[m][0] = 0;
        }
    }
}


int main(){
    return 0;
}