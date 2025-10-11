#include<bits/stdc++.h>
using namespace std;

int sLargest(vector<int> arr){
    int largest  = arr[0];
    int slargest = INT_MIN;

    for(int i=1; i<=arr.size()-1; i++){
        if(largest<arr[i]){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}


int sSmallest(vector<int> arr){
    int smallest  = arr[0];
    int ssmallest = INT_MAX;

    for(int i=1; i<=arr.size()-1; i++){
        if(smallest>arr[i]){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int uniqueElement(vector<int> arr){
    int i = 0;
    for(int j= 1; j<=arr.size()-1; j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> arr = {0, 3, 3, 4, 4, 4, 4, 5,5};
    int uniqueelement = uniqueElement(arr);

    cout<< uniqueelement;
}

