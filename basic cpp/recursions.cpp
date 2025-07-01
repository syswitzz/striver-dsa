#include<bits/stdc++.h>
using namespace std;


// PRINT LINEARLY FROM 1 TO N
void prob1(int i, int n){
    if(i>n) return;      // base condition
    else cout << i << endl;
    prob1(i+1, n);
}


// PRINT LINEARLY FROM N TO 1 - USING BACKTRACKING (VVIP)
void prob2(int i, int n){
    if (i>n) return;
    prob2(i+1, n);
    cout << i << endl;
}


// RETURN SUM OF N NUMBERS - PARAMETARISED 
void sumN(int n, int sum){
    if (n<1) {
        cout<< sum;
        return; 
    }
    sumN(n-1, sum+n);
}


// RETURN SUM OF N NUMBERS - FUNCTIONAL
int sumNfunc(int n) {
    if(n==0) return 0;
    return n+sumNfunc(n-1);
} 


// RETURN FACTORIAL OF N  |  TC: O(n) , SC: O(n)
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}


// REVERSE OF AN ARRAY
void reverseArray(int i, int arr[], int n){
    if (i>=n/2) return;   // base condition

    swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, arr, n);
}


// PALINDROME TRUE OR FALSE
bool palindrome(int i, string s){
    if (i>=s.size()/2) return true;
    if (s[i]!=s[s.size()-i-1]) return false;
    return palindrome(i+1, s);
}


// FIBONACCI (VVIP)  |  TC - near O(2^n) (exponential)
int fibonacci(int n){
    if (n<=1) return n;    // f(0) = 0, f(1) = 1

    int last = fibonacci(n-1);    // first recursion tree
    int sLast = fibonacci(n-2);    // second recursion tree

    return last+sLast;
}
