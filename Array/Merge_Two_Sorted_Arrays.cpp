
//Using O(1) space
// Input: ar1[] = {1, 5, 9, 10, 15, 20};
//        ar2[] = {2, 3, 8, 13};
// Output: ar1[] = {1, 2, 3, 5, 8, 9}
//         ar2[] = {10, 13, 15, 20}

void merge2SortedArrays(vector<int> arr1,vector<int> arr2){
    int m = arr1.size(), n = arr2.size();
    for(int i=n-1; i >= 0; i--){
        int j, last = arr1[m-1];
        for(j=m-2; j >= 0 && arr1[j] > arr2[i]; j--){
            arr1[j+1] = arr1[j];
        }

        if(j != m-2 || last > arr2[i]){
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}
