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


// MOVE ZEROES TO THE END  |  TC - O(N)  |  SC - O(1)
void moveZeroes(vector<int>& arr) {
    int i = 0;

    for(int j=0; j<arr.size(); j++){
        if (arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
}


// INTERSECTION OF TWO ARRAYS  |  TC - O(N1+N2)  |  SC - O(1) for solving
vector<int> intersectionOf(vector<int> arr1, vector<int> arr2){
    // two pointers method
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> intersectionArray;

    int i = 0;
    int j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]=arr2[j]){
            intersectionArray.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }

    }
    return intersectionArray;
}


// UNION OF TWO ARRAYS  |  TC - O(N1+N2)  |  SC - O(1) for solving but O(N1+N2) to return the result
vector<int> unionOf(vector<int> arr1, vector<int> arr2){
    // two pointers method
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionArray;

    int i = 0;
    int j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArray.size()==0 || unionArray.back()!=arr1[i]){
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArray.size()==0 || unionArray.back()!=arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
        }   
    }
    while(i<n1){
        if(unionArray.size()==0 || unionArray.back()!=arr1[i]){
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArray.size()==0 || unionArray.back()!=arr2[j]){
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}




int main(){
    vector<int> arr1 = {0,1,2,3,7, 7,7};
    vector<int> arr2 = {0, 1, 2, 3};
    vector<int> arr = unionOf(arr1, arr2);

    for(auto it: arr){
        cout<< it << ", ";
    }
    return 0;
}
