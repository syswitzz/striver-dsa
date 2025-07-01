#include<bits/stdc++.h>
using namespace std;


// PRINT LINEARLY FROM 1 TO N
int numCount = 0;
void prob1(int n){
    numCount++;
    if(numCount>n) return;
    else cout << numCount<< endl;
    prob1(n);
}


// SUM OF N NUMBERS
int sumN = 0;
int NnumbersSum(int N){
    if (N==0) return sumN;
    else sumN = sumN +N;
    return NnumbersSum(N-1);
}


int main(){
    int n;
    cin >> n;
    cout << NnumbersSum(n) << endl;
    return 0;
}