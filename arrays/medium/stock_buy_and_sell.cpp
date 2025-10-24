#include <iostream>
#include <vector>
using namespace std;


// STOCK BUY AND SELL  |  O(n)  |  O(1)
int stock(vector<int> arr){
    int buy = arr[0];
    int max_profit = 0;

    for(int i=1; i<arr.size(); i++){
        int profit = arr[i]-buy;
        max_profit = max(max_profit, profit);
        buy = min(buy, arr[i]);
    }

    return max_profit;
}

int main(){
    vector<int> arr = {2,3,5,5,5,5,3};
    int me = stock(arr);

    cout << me;
    return 0;
}
