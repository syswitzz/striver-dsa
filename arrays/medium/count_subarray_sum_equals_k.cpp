#include<bits/stdc++.h>
using namespace std;


// COUNT SUBARRAY SUM EQUALS K (brute)  |  O(n(n-1)/2)  | O(1)
int brute(vector<int> nums, int k){
    int n = nums.size();
    int total = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(sum==k){
                total++;
            }
        }
    }
    return total;
}


// COUNT SUBARRAY SUM EQUALS K (optimal)  |  O()
int optimal(vector<long long> nums, int k){
    int n = nums.size();
    int sum = 0;
    int cnt = 0;
    unordered_map<long long, int> hashmap;    // stores  {prefixsum, count}
    hashmap[0] = 1;     // storing {0, 1} by default helps when sum=k (because then rem=0) so cnt += 1

    for(int i=0; i<n; i++){
        sum += nums[i];
        if(hashmap.find(sum - k)!= hashmap.end()){
            cnt += hashmap[sum - k];
        }
        hashmap[sum] = hashmap[sum] +1;
    }

    return cnt;
}



int main(){
    vector<long long> nums = {1,2,3,-3,1,1,1,4,2,-3};

    int total = optimal(nums, 3);
    cout << total<< endl;
}