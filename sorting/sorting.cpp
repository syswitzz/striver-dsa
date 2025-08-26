#include <bits/stdc++.h>
using namespace std;


// MERGE SORT  | best, avg, worst TC - O(nlogn)  |  worst SC - O(n) 
// Merge sort is a sorting algorithm that repeatedly divides the unsorted array into two halves, sorts each half recursively, and then merges the sorted halves to produce the final sorted list.
void merge(vector<int> &arr, int low,int mid,int high){
    int left=low;
    int right= mid+1;
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}


// QUICK SORT  |  