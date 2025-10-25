#include <iostream>
#include <vector>
using namespace std;



// REARRANGE ARRAY ELEMENTS BY SIGN (POS = NEG) |  O(n+n/2)  |  O(n)
void rearrangeBrute(vector<int> &arr){
    vector<int> pos_arr;
    vector<int> neg_arr;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0){
            neg_arr.push_back(arr[i]);
        }
        else{
            pos_arr.push_back(arr[i]);
        }
    }

    for(int j =0; j<arr.size()/2; j++){
        arr[2*j] = pos_arr[j];
        arr[2*j+1] = neg_arr[j];
    }
}



// REARRANGE ARRAY ELEMENTS BY SIGN (POS = NEG) |  O(n)  |  O(n)
vector<int> rearrangeOptimal(vector<int> &arr){
    vector<int> ans(arr.size(), 0);
    int pos_index = 0;
    int neg_index = 1;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0){
            ans[neg_index] =  arr[i];
            neg_index+=2;
        }
        else{
            ans[pos_index] = arr[i];
            pos_index+=2;
        }
    }
    return ans;
}



// REARRANGE ARRAY ELEMENTS BY SIGN (POS != NEG) |  O(2n)  |  O(n)
void rearrangeBrute2(vector<int> &arr){
    vector<int> pos_arr;
    vector<int> neg_arr;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0){
            neg_arr.push_back(arr[i]);
        }
        else{
            pos_arr.push_back(arr[i]);
        }
    }

    if(pos_arr.size()>neg_arr.size()){
        for(int j=0; j<neg_arr.size(); j++){
            arr[2*j] = pos_arr[j];
            arr[2*j+1] = neg_arr[j];
        }
        int res = 2*neg_arr.size();
        for(int k=neg_arr.size(); k<pos_arr.size(); k++){
            arr[res] = pos_arr[k];
            res++;
        }
    }
    else{
        for(int j=0; j<pos_arr.size(); j++){
            arr[2*j] = pos_arr[j];
            arr[2*j+1] = neg_arr[j];
        }
        int res = 2*pos_arr.size();
        for(int k=pos_arr.size(); k<neg_arr.size(); k++){
            arr[res] = neg_arr[k];
            res++;
        }
    }
}




int main(){
    vector<int> arr = {-2,-3,2, 4, -5,5, 7,3, 5};
    rearrangeBrute2(arr);

    for(int it : arr) cout << it;
    return 0;
}
