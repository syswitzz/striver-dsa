#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


// LONGEST CONSECUTIVE ELEMENTS (brute)  | O(n+nlogn) |  O(1)
int longestCE(vector<int> nums){
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int max_len = 1;
    int len = 1;

    for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]+1){
            len++;
        }
        else if(nums[i]==nums[i-1]){
            continue;
        }
        else{
            len = 1;
        }
        max_len = max(len, max_len);
    }
    return max_len;
}


// LONGEST CONSECUTIVE ELEMENTS (optimal)  | O(3n) |  O(n)
int longestCE2(vector<int> nums){
    int n = nums.size();
    unordered_set<int> num(nums.begin(), nums.end());   // TC - O(1) * O(n) in best and O(n) * O(n) in worst case. second O() is for lookup 

    int max_count = 1;
    for(int it: num){   // TC - O(n)
        if(num.find(it-1)==num.end()){
            int count = 1;
            while(num.find(it+count)!=num.end()){   // using set DS instead of linear search.  TC - O(2n) in worst case
                count++;
            }
            max_count = max(max_count, count);
        }
    }
    return max_count;
}


int main(){
    vector<int> arr = {3,6,2,9,7,5,1};
    cout << longestCE2(arr);
    return 0;
}