#include <bits/stdc++.h>
using namespace std;


// SELECTION SORT
void selectionSort(int arr[], int array_length){
    for (int i=0; i<=array_length-2; i++){    // 2 because to sort array of 5 elements we need only 4 swaps

        int minimum = arr[i];
        for (int j=i; j<=array_length; j++){
            if (arr[j]<minimum) minimum = arr[j];
        }

        swap(arr[i], minimum);
    }
}



int main(){
    int arr[5] = {4, 6 ,3, 0, 2};
    selectionSort(arr, 5);

    for(auto i : arr) cout << i << endl;
}