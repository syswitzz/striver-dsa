#include <iostream>
#include <vector>
using namespace std;


// STOCK BUY AND SELL  |  O(n)  |  O(1)
int maxProfit(vector<int>& prices) {
    int max=INT_MIN;
    int min=prices[0];
    for (int i=1;i<prices.size();i++){
        int profit=prices[i]-min;
        if (profit>max) max=profit;
        if (prices[i]<min) min=prices[i];
    }
    if (max>0) return max;
    return 0; 
}  

int main(){
    vector<int> arr = {2,3,5,5,5,5,3};
    int me = maxProfit(arr);

    cout << me;
    return 0;
}
