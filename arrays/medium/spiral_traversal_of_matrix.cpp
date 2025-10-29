#include<bits/stdc++.h>
using namespace std;


// SPIRAL TRAVERSAL OF MATRIX  |  O(n^2)  |  O(n^2) for answer O(1) for solving
vector<vector<int>> spiralTraversal(int n){
    vector<vector<int>> matrix(n, vector<int>(n));
    int num = 1; 
    int left = 0; int top = 0;
    int right = n-1; int bottom = n-1;
    
    while(num<=n*n){
        for(int i=left; i<=right; i++){
            matrix[top][i]=num;
            num++;
        }
        top++;
        for(int i=top; i<=bottom; i++){
            matrix[i][right]=num;
            num++;
        }
        right--;
        for(int i=right; i>=left; i--){
            matrix[bottom][i]=num;
            num++;
        }
        bottom--;
        for(int i=bottom; i>=top; i--){
            matrix[i][left]= num;
            num++;
        }
        left++;
    }
    return matrix;
}


int main(){
    int n = 5;
    vector<vector<int>> arr;
    arr = spiralTraversal(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}