#include<bits/stdc++.h>
#include<iostream>
#include <algorithm>  //for max function
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


// MISSING NUMBER (better)  |  TC - O(2n)  |  SC - O(n)
int missingNumber(vector<int> arr, int n){
    int hashh[n+1]= {0};

    for(int i=0; i<n-1; i++){
        hashh[arr[i]] = 1; 
    }

    for(int j=1; j<n+1; j++){
        if(hashh[j]==0){
            return j;
        }
    }
    return 0;
}

// MISSING NUMBER (best)  |  TC - O(n)  |  SC - O(1)
int missingNumberSum(vector<int> arr, int n){
    
    int sum = n*(n+1)/2;    // can not store very big data thats why xor is better
    int sumarr = 0;

    for(int i=0; i<arr.size(); i++){
        sumarr+= arr[i];
    }

    int missingNum = sum-sumarr;
    return missingNum;
}

// MISSING NUMBER (optimal)  |  TC - O(n)  |  SC - O(1)
int missingNumberXOR(vector<int> arr, int n){
    int XOR1 = 0;
    int XOR2 = 0;

    for(int i=0; i<n-1; i++){
        XOR2 = XOR2^arr[i];
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^n;
    return XOR1^XOR2;
}


// MAX CONSECUTIVE 1s  |  TC - O(n)  |  SC - O(1)
int maxConsecutive(vector<int> arr){
    int count = 0;
    int maxi = 0;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]==1){
            count++;
            maxi=std::max(maxi, count);
        }
        else count=0;
    }
    return maxi;
}


// FIND THE NUMBER THAT APPEARS ONCE  (brute)
int onceNumber(vector<int> arr){
    int maxi=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }

    int hashh[maxi] = {0};

    for(int j=0; j<arr.size(); j++){
        hashh[arr[j]]++;
    }

    for(int k=0; k<arr.size(); k++){
        if(hashh[arr[k]]==1) return k;
    }
    return 0;
}

// FIND THE NUMBER THAT APPEARS ONCE  (better)  |  TC - O(nlogn+n/2+1)  |  SC - O(n/2 +1)
int onceNumberMap(vector<int> arr){
    map<long long, int> mapp;

    for(int i=0; i<arr.size(); i++){    // n *logn
        mapp[arr[i]]++;
    }
    
    for(auto it: mapp){                 // n/2 + 1
        if(it.second==1) return it.first;
    }
    return 0;
}


// FIND THE NUMBER THAT APPEARS ONCE OTHER TWICE  (optimal)  |  TC - O(n)  |  SC - O(1)
int onceNumberXOR(vector<int> arr){
    int XOR = 0;

    for(int i=0; i<arr.size(); i++){
        XOR = XOR^arr[i];
    }
    return XOR;
}


// SUBARRAY - contigious part of array
// LONGEST SUBARRAY WITH SUM K (brute)  |  TC - O(n^2)  |  SC - O(n)
int longestSubarrayBrute(vector<int> arr, int k){
    int maxlen =0;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum+=arr[j];
            if(sum==k){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

// LONGEST SUBARRAY WITH SUM K (better)  |  TC - O(n)  |  SC - O(n)
// Optimal if array includes negatives
int longestSubarrayNegative(vector<int> arr, int k){
    map<long long, int> hashmap;

    int prefixsum =0;
    int maxlen =0;

    for(int i=0; i<arr.size(); i++){
        prefixsum+=arr[i];

        if(prefixsum==k){
            maxlen = max(maxlen, i+1);
        }

        int rem = prefixsum-k;
        // if element is not found in hashmap it returns an iterator at end
        if(hashmap.find(rem) != hashmap.end()){
            int len = i - hashmap[rem];
            maxlen = max(len, maxlen);
        }
        
        hashmap[prefixsum] = i;
    }
    return maxlen;
}

// LONGEST SUBARRAY WITH SUM K (optimal)  |  TC - O(2n)  |  SC - O(1)
int longestSubarrayPositive0(vector<int> arr, int k){
    int sum = 0;
    int maxlen = 0;

    int j =0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        while(sum>k){
            sum -= arr[j];
            j++;
        }
        if(sum==k){
            maxlen = max(i-j+1, maxlen);
        }
    }
    return maxlen;
}




int main(){
    vector<int> arr = {2,5,1,0,4,2,0,0,0,1,3,9,3,2,4,1};

    cout << longestSubarrayNegative(arr, 7);
    return 0;
}
