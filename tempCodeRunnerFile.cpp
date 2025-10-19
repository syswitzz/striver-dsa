vector<int> unionOf(vector<int> arr1, vector<int> arr2){
    // two pointers method
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> unionArray;

    int i = 0;
    int j = 0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j] && (unionArray.back()!=arr1[i] || unionArray.empty())){
            unionArray.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j] && unionArray.back()!=arr2[j]){
            unionArray.push_back(arr2[j]);
            j++;
        }
        else if(unionArray.back()!=arr1[i]){
            unionArray.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while(i<n1){
        if(arr1[i]>unionArray.back()){
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(arr2[j]>unionArray.back()){
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    return unionArray;
}