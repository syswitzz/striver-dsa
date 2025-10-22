#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


// TWO SUM PROBLEM WITH INDICES (brute) |  O(n(n+1)/2)  |  O(1)
vector<int> twosumBrute(vector<int> arr, int number){
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j]==number){
                return {i, j};
            }
        }
    }
    return {0,0};
}

// TWO SUM PROBLEM WITH INDICES USING HASHMAP (optimal) |  O(nlogn)  |  O(n)
// note - this solution is optimal if it asks for indices of elements as well
vector<int> twosumHashmap(vector<int> arr, int number){
    map<int, int> mp;

    for(int i=0; i<arr.size(); i++){
        int req_num = number-arr[i];
        if(mp.find(req_num) != mp.end()){
            return {i, mp[req_num]};
        }
        else{
            mp[arr[i]] = i;
        }
    }
    return {0,0};
}

// TWO SUM PROBLEM USING GREEDY ALGO (optimal) |  O(nlogn + n)  |  O(1)
int twosumGreedy(vector<int> arr, int number){
    sort(arr.begin(), arr.end());  //nlogn
    int i=0, j=arr.size()-1;

    while(i<j){
        int sum = arr[i] + arr[j];
        if(sum  > number){
            j--; 
            continue;
        }
        else if(sum < number){
            i++;
            continue;
        } 
        else return 1;
    }
    return 0;
}



int main(){
    vector<int> arr = {3,7,2,8,1};
    vector<int> result;

    result = twosumHashmap(arr, 14);

    for(auto it: result) cout << it;

    return 0;
}