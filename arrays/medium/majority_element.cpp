#include <iostream>
#include <vector>
#include <map>
using namespace std;


// MAJORITY ELEMENT (>N/2) (better) |  O(nlogn + n)  |  O(n)
int majorityElement(vector<int> arr){
    map<int, int> hashmap; // O(n)

    for(int i=0; i<arr.size(); i++){ //O(nlogn)
        hashmap[arr[i]]++;
    }
    for(auto it: hashmap){  //O(n)
        if(it.second>arr.size()/2) return it.first;
    }
    return 0;
}

// MAJORITY ELEMENT (>N/2) (optimal) |  O(n+ n)  |  O(1)
// MOOSE'S VOTING ALGORITHM
int majorityElementOptimal(vector<int> arr){
    int element;
    int count = 0;

    for (int i=0; i<arr.size(); i++){
        if(count==0){
            count =1;
            element= arr[i];
        }
        else if (arr[i]==element){
            count++;
        }
        else count--;
    }

    // extra verification steps
    int countt=0;
    for(int i=0; i<arr.size(); i++) if(arr[i]==element) countt++;
    
    if(countt>arr.size()/2) return element;
    else return 0;
}


int main(){
    vector<int> arr = {2,3,5,5,5,5,3};
    int me = majorityElementOptimal(arr);

    cout << me;
    return 0;
}
