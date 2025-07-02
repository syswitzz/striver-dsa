#include <bits/stdc++.h>
using namespace std;


// SELECTION SORT  |  O(n^2) - worst/ average/ best
void selectionSort(int arr[], int n){
    for (int i=0; i<=n-2; i++){    // to sort array of 5 elements we need only 4 swaps

        // finds the minima in the range (i -> end)
        int minima = i;
        for (int j=i; j<=n-1; j++){
            if (arr[j]<arr[minima]) minima = j;
        }

        // swapping
        swap(arr[i], arr[minima]);
    }
}


// BUBBLE SORT  |  O(n^2)  - worst/avg  |  O(n) - best
void bubbleSort(int arr[], int n){

    for(int i=n-1; i>=1; i--){    // to sort array of 5 elements we need only 4 loops 

        int didSwap=0;    // optimization for best case scenario (4, 7, 8, 9, 9) i.e, everything already sorted

        for (int j=0; j<=i-1; j++){     // runs for n > n-1 > n-2... tinmes

            if(arr[j]> arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didSwap++;    // optimization
            }
        }
        if (didSwap==0) break;    // optimization
    }
}


// INSERTION SORT  |  O(n^2)  - worst/avg  |  O(n) - best
void insertionSort(int arr[], int n){

    for (int i=0; i<=n-1; i++){
        int j = i;

        while(j>=1 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]); 
            j--;
        }
    }
}


int main(){
    int arr[9] = {8, 0, 6,301, 52, 69, 20, 8, 3};
    insertionSort(arr, 9);

    for(auto i : arr) cout << i << endl;
}