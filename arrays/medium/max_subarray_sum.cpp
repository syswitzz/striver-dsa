#include <iostream>
#include <vector>
using namespace std;


// MAXIMUM SUM OF SUBARRAY (better)  |  O(n^2)  |  O(1)
int subarrSum(vector<int> arr){
    int max_sum = 0;
    for(int i=0; i<arr.size(); i++){
        int sum=0;
        for(int j=i; j<arr.size(); j++){
            sum+=arr[j];
            if(max_sum<sum) max_sum=sum;
        }
    }
    return max_sum;
}


// MAXIMUM SUM OF SUBARRAY EMPTY SET ALLOWED (optimal)  |  O(n)  |  O(1)
// KADANE'S ALGORITHM
int subarrSum2(vector<int> arr){
    int max_ele = 0;
    int sum = 0;

    for(int i=0; i<arr.size(); i++){
        sum = max(0, sum+arr[i]);
        max_ele = max(max_ele, sum);
    }
    return max_ele;
}

// MAXIMUM SUM OF SUBARRAY EMPTY SET NOT ALLOWED (optimal)  |  O(n)  |  O(1)
int subarrSum3(vector<int> arr){
    int max_ele = INT_MIN;
    int sum =0;

    for(int i=0; i<arr.size(); i++){
        sum = max(arr[i], sum+arr[i]);
        max_ele = max(sum, max_ele);
    }
    return max_ele;
}

// PRINT MAXIMUM SUM OF SUBARRAY EMPTY SET ALLOWED (optimal)  |  O(n)  |  O(1)
vector<int> subarrSumPrint(vector<int> arr){
    int max_ele = 0;
    int sum = 0;
    int start=-1; int end=-1;
    int temp_start=0;

    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];

        if(sum<0){
            sum =0;
            temp_start = i+1;
        }

        else if(sum>max_ele){
            max_ele = sum;
            start = temp_start;
            end = i;
        }
    }

    vector<int> result;
    if(start==-1) return result;
    else{
        for(int j=start; j<=end; j++) result.push_back(arr[j]);
    }

    return result;
}


int main(){
    vector<int> arr = {-3, -5,7, -4, -2, 7};
    vector<int> sum = subarrSumPrint(arr);

    for(auto it: sum) cout << it;
    return 0;
}