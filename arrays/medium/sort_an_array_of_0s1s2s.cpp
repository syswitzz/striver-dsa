#include <iostream>
#include <vector>
using namespace std;


// SORT AN ARRAY OF 0s, 1s, 2s (brute)  | O(2n) | O(1)  
void sortarray1(vector<int> &arr){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]==0) count0++;
        if(arr[i]==1) count1++;
        if(arr[i]==2) count2++;
    }

    for(int j=0; j<count0; j++) arr[j]=0;
    for(int k=count0; k<count0+count1; k++) arr[k]=1;
    for(int l=count0+count1; l<arr.size(); l++) arr[l]=2;
}

// SORT AN ARRAY OF 0s, 1s, 2s USING DUTCH NATIONAL FLAG ALGO (optimal)  | O(n) | O(1)  
void sortarrayOpt(vector<int> &arr){
    int low =0;
    int mid =0;
    int high =arr.size()-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid], arr[low]);
            mid++; low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main(){
    vector<int> arr = {0,2,1,0,0,1,2,1,2,2,0,2};
    sortarrayOpt(arr);

    for (auto it: arr) cout << it;
    return 0;
}