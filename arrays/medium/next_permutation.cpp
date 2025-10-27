#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ALTERNATIVE - just use next_permutation(arr.begin(), arr.end()) function
// NEXT PERMUTATION FUNC  |  O(3n)  |  O(n) for answer not for solving
vector<int> nextPermutation(vector<int> arr){
    int dip_index = -1;
    for(int i=arr.size()-2; i>=0; i--){
        if(arr[i] < arr[i+1]) {
            dip_index = i;
            break;
        }
    }

    if(dip_index==-1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i]> arr[dip_index]){
            swap(arr[dip_index], arr[i]);
            break;
        }
    }

    reverse(arr.begin()+dip_index+1, arr.end());
    return arr;
}




int main(){
    vector<int> arr = {2,1,5,4,3,0,0};
    vector<int> res;
    res = nextPermutation(arr);

    for(auto it: res) cout << it;
    return 0;
}