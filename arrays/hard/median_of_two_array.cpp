#include<bits/stdc++.h>
using namespace std;

vector<int> findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums3;
    int n1 = nums1.size();
    int n2 = nums2.size();

    int n1c = 0;
    int n2c = 0;

    while(n1c<n1 && n2c<n2){
        if(nums1[n1c]<=nums2[n2c]){
            nums3.push_back(nums1[n1c]);
            n1c++;
        }
        else{
            nums3.push_back(nums2[n2c]);
            n2c++;
        }
    }
    while(n1c<n1){
        for(int i=n1c; i<n1; i++){
            nums3.push_back(nums1[i]);
            n1c++;
        }
    }
    while(n2c<n2){
        for(int i=n2c; i<n2; i++){
            nums3.push_back(nums2[i]);
            n2c++;
        }
    }
    return nums3;
}

int main(){
    vector<int> num1 = {1,2,3,4};
    vector<int> num2 = {7,8,9,10};

    vector<int> num3 = findMedianSortedArrays(num1, num2);

    for(auto it: num3) cout << it;
    return 0;
}