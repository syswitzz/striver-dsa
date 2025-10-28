#include<bits/stdc++.h>
using namespace std;


// SEAT MATRIX ZEROES (brute) 
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

int main(){
    return 0;
}