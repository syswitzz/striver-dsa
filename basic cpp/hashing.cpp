#include<bits/stdc++.h>
using namespace std;


// array = {2,3,4,5,3,0}
// how many times 0,1,2,3,4,5 comes in this array? we have to loop through the entire array of strength 'N'
// '0' comes == 1 times  |  TC - O(N)
// '1' comes == 0 times  |  TC - O(N) 
// for Q elements  |  TC - O(N*Q)
// which is lot so thats why we use hashing which scans the data one time and makes a new array


// INTEGER HASHING  |  (only till 1e7)
int integerHashing(int arr[], int n){
    // returns how many times i appears in array arr

    int sizeOfHash = 101;      // size of hash is only 0-100 (but this can be modified or made dynamic)
    int sizeOfArray = 13;      // depends on parameter arr
    cout << sizeOfArray << endl;
    int hash[sizeOfHash]={0};

    for(int i=0; i<sizeOfArray; i++){
        hash[arr[i]] +=1;
    } 

    return hash[n];
}


// CHARACTER HASHING  |  (only for lowercase letters)
// in ASCII - 'a' = 97, 'z' = 122
int characterHashing(string s, char ch){
    int hash[26] = {0};     

    for(int i=0; i<=s.size()-1; i++){
        hash[s[i]-'a']+=1;
    }

    return hash[ch-'a'];
}


// CHARACTER HASHING  |  (for all 256 ascii characters)
int characterHashing256(string s, char ch){
    int hash[256] = {0};     

    for(int i=0; i<=s.size()-1; i++){
        hash[s[i]]+=1;
    }

    return hash[ch];
}


// HASHING USING MAP  |  (better)
// normal map is by default ordered
int characterHashingMap(string s, char ch){
    map<char, int> mpp;   // use int, int for integer hashing
    
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]+=1;
    }
    return mpp[ch];
}


// HASHING USING UNORDERED MAP  |  (best)
int characterHashingUnMap(string s, char ch){
    unordered_map<char, int> mpp;   // use int, int for integer hashing
    
    for(int i=0; i<s.size(); i++){
        mpp[s[i]]+=1;
    }
    return mpp[ch];
}


// prefer using unordered map before normal map
// because O of map for fetching and pushing is log(n)
// but O of unordered_map for __ and __ is 1
// in worst case its 0 but rarely happens (happens because of collisons)



int main(){
    string s = "apple&dfkffvfwowowow&";
    char ch;

    while (true){
        cin >> ch;
        cout << characterHashingUnMap(s, ch);
    }
    return 0;
}