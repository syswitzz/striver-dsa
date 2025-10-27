#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// LEADERS IN A ARRAY  |  O(n)  |  O(n) for returning answer
vector<int> leader(vector<int> nums){
    vector<int> ans;
    int maxi = INT_MIN;
    int n = nums.size();

    for(int i=n-1; i>=0; i--){
        maxi = max(maxi, nums[i]);
        if(nums[i]>=maxi){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,6,2,8,4,1};
    for(int it: leader(arr)) cout << it;
    return 0;
}