#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sLargest(vector<int> arr){
    int largest  = arr[0];
    int slargest = INT_MIN;

    for(int i=1; i<=arr.size()-1; i++){
        if(largest<arr[i]){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}


int sSmallest(vector<int> arr){
    int smallest  = arr[0];
    int ssmallest = INT_MAX;

    for(int i=1; i<=arr.size()-1; i++){
        if(smallest>arr[i]){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int uniqueElement(vector<int> arr){
    int i = 0;
    for(int j= 1; j<=arr.size()-1; j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}


void rotateElementby1(vector<int> &arr){
    for(int i=0; i<=arr.size()-2; i++){
        swap(arr[i], arr[i+1]);
    }
}


// LEFT ROTATE BY D (BRUTE)  |  TC - O(n+d)  |  SC - O(d)
void rotateElementbyD(vector<int> &arr, int d){
    int n= arr.size();
    if(d>n) d = d%n;

    vector<int> temp;
    for(int i=0; i<d; i++) temp.push_back(arr[i]);

    for(int j=0; j<n-d; j++){
        arr[j] = arr[d+j];
    }

    for(int k=n-d; k<n; k++){
        arr[k] = temp[k-(n-d)];
    }
}


void reverse(vector<int> &arr, int start, int end){
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// LEFT ROTATE BY D (OPTIMAL)  |  TC - O(n)  |  SC - O(0)
void rotateElementbyD_optimal(vector<int> &arr, int d){
    int n = arr.size();
    if(d>n) d=d%n;

    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}


// RIGHT ROTATE BY D (OPTIMAL)  |  TC - O(n)  |  SC - O(0)
void rightRotateElementbyD_optimal(vector<int> &arr, int d){
    int n = arr.size();
    if(d>n) d=d%n;

    reverse(arr, 0, n-d-1);
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-1);
}


// MOVE ZEROES TO THE END 
void moveZeroes(vector<int>& arr) {
    int j = 0; // index to place the next non-zero element

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}


int main(){
    vector<int> arr = {0,2,0,4,0, 0,6,7};
    moveZeroes(arr);

    for(auto it: arr){
        cout<< it << ", ";
    }
    return 0;
}
