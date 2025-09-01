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


// QUICK SORT  | best, avg TC - O(nlogn), worst TC - O(n^2)  |  worst SC - O(logn) 
// Quick sort is a sorting algorithm that picks a pivot element, partitions the array into two halves such that elements less than the pivot go to the left and elements greater go to the right, then recursively sorts the partitions. It is generally faster than merge sort in practice due to better cache performance and in-place sorting.
int quick(vector<int> &arr, int low, int high){
    int pivotValue = arr[low];
    int i = low;
    int j = high;

    while(true){
        while(arr[i]<=pivotValue && i<=high-1){
            i++;
        }
        while(arr[j]>pivotValue && j>=low+1){
            j--;
        }
        if(i>=j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low>=high) return;
    
    int pivot = quick(arr, low, high);;

    quickSort(arr, low, pivot-1);
    quickSort(arr, pivot+1, high);
}

int main(){
    vector<int> arr = {8, 0, 1,0, 7,6,9, 4, 2};
    quickSort(arr, 0, arr.size()-1);

    for(auto it : arr) cout << it << ", ";
}