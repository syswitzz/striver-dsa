#include<bits/stdc++.h>
using namespace std;


// COUNT
void counts(int n){

    // method 1
    int count1 = 0;

    while (n>0) {
        n = n/10;
        count1++;
    }

    // method 2
    int count2 = int (log10(n) + 1);
    cout<< count2;
}


// TIME COMPLEXITY
// division by 10 - O(log base 10 (N))
// division by 3 - O(log base 3 (N))


// REVERSE
void reverse(int n){

    int number;

    while(n>0){
        int count_ = log10(n)+1;
        number += (n%10)*(pow(10, count_-1));
        n = n/10;
    }
    
    cout << number;
}


// ARMSTRONG NUMBER  -  cube of all digits == mumber itself
int armstrongs(int n){
    int as_num=0;
    int n_dupe = n;

    while (n>0){
        int remainder = (n%10);
        int num =  pow(remainder, 3);
        as_num += num;
        n = n/10;
    }

    if(as_num==n_dupe) return true;
    else return false;
}


// DIVISIONS
void divisions(int n){

    // method 1  -  O(N)
    vector<int> arr1;

    for (int i=1; i<=n; i++){
        if (n%i==0) arr1.emplace_back(i);
    }

    // method 2  - my attempt
    vector<int> arr2;

    int divisor = 1;
    int divident = 0;

    while (divisor!=divident){
        if (n%divisor==0) {
            divident=n/divisor;
            arr2.emplace_back(divisor);
            if (divisor==divident) break;
            arr2.emplace_back(divident);
            
        }
        divisor++;
    }
    sort(arr2.begin(), arr2.end());

    // method 3  -  striver method  ||  O(sqrt(N)
    vector<int> arr3;

    for (int i = 1; i*i<=n; i++) {
        if(n%i==0){
            arr3.emplace_back(i);
            if (i!=n/i) arr3.emplace_back(n/i);
        }
    }

    // O (nlogn)  -  n is number of factors
    sort(arr3.begin(), arr3.end());

    // O (n)  -  n is number of factors
    for(auto it=arr3.begin(); it!= arr3.end(); it++) cout << *(it) << " ";
}


//  GCD / HCF
int HCF(int n1, int n2) {

    // O(min(n1, n2))
    int hcf=1;

    for (int i=min(n1, n2); i>1; i--){
        if(n1%i==0 && n2%i==0){
            hcf = i;
            break;
        }
    }
    return hcf;

    // euclidean method  -  O(logbase phi (min(n1, n2)))
    while(n1>0 || n2>0){
        if (n1>n2) n1 = n1%n2;
        else n2 = n2%n1;

        if (n1==0) return n2;
        else if(n2==0) return n1;
    }
}

