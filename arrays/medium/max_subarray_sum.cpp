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



int main(){
    vector<int> arr = {-3, -5, -4, -2};
    int sum = subarrSum2(arr);

    cout << sum;
    return 0;
}