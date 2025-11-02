#include<bits/stdc++.h>
using namespace std;


// Ques - Find element at Row = x and Column = y in PT.
// Soln - nCr = n!/(r! * (n-r)!) where n = x-1, r = y-1 
// Or - nCr = n*n-1*n-2.. till n-r+1/ r!
// FIND nCr  |  TC - O(r)
int nCr(int n, int r){
    int result = 1;
    for(int i=0; i<r; i++){
        result = result * (n-i);
        result = result / i +1;
    }
    return result;
}


// GENERATE NTH ROW OF PASCAL TRIANGLE  |  TC - O(n)
vector<int> getRow(int n) {
    // derive the formula on paper using observation itll be - ans*(row-col)/col 
    // row = col = 6 = n. (observation)
    int ans = 1;
    vector<int> ansRow;

    ansRow.push_back(ans);

    for(int i =1; i<n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        ansRow.push_back(ans);
    }
    return ansRow;
}


// GIVEN N, PRINT THE PASCAL TRIANGLE   |  TC - O(n^2)
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> pt;
    for(int i=1; i<=n; i++){
        pt.push_back(getRow(i));
    }
    return pt;
}


int main(){
    for(auto it: pascalTriangle(5)){
        for(auto i: it){
            cout<< i;
        }
        cout<< endl;
    }
    return 0;
}