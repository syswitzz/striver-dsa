#include<bits/stdc++.h>
using namespace std;


// MAJORITY ELEMENTS II (brute)  |  O(n^2)  |  O(1)
vector<int> brute(vector<int>& nums) {
    int n = n;
    vector<int> elements;

    for(int i=0; i<n; i++){
        int element = nums[i];
        if(elements.empty() || elements[0]!=element){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(nums[j]==element){
                    cnt++;
                }
            }
            if(cnt>n/3){
                elements.push_back(element);
            }
        }
        if(elements.size()>=2){
            break;
        }
    }
    return elements;
}


// MAJORITY ELEMENTS II (better)  |  O(nlogn)  |  O(n)
vector<int> better(vector<int>&nums){
    int n = n;
    map<int, int> mp;
    vector<int> ans;

    for(int i=0; i<n; i++){
        mp[nums[i]]++;
        if(mp[nums[i]]>n/3){
            if(ans.size()!=0 && nums[i]==ans[0]) continue;
            ans.push_back(nums[i]);
            if(ans.size()==2) break;
        }
    }
    return ans;
}

// MAJORITY ELEMENTS II (optimal)  |  O(nlogn)  |  O(n)
vector<int> optimal(vector<int>&nums){
    int n = nums.size();
    int ct1=0, ct2=0;
    int el1=INT_MIN, el2=INT_MIN;

    for(int i=0; i<n; i++){
        if(nums[i]==el1) ct1++;
        else if(nums[i]==el2) ct2++;
        else if(ct1==0 && el2!=nums[i]){
            ct1 = 1;
            el1 = nums[i];
        }
        else if(ct2==0 && el1!=nums[i]){
            ct2 = 1;
            el2 = nums[i];
        }
        else ct1--, ct2--;
    }
    vector<int> ans;
    ct1=0, ct2=0;

    for(int i=0; i<n; i++){
        if(nums[i]==el1) ct1++;
        if(nums[i]==el2) ct2++;
    }
    if(ct1>n/3) ans.push_back(el1);
    if(ct2>n/3) ans.push_back(el2);

    sort(ans.begin(), ans.end());
    return ans;
}



int main(){
    vector<int> arr = {4,5,5,5,5,5,5,5,5,3,3,3,3,3,3};
    vector<int> ans = optimal(arr);

    for(auto it: ans) cout << it;
    return 0;
}