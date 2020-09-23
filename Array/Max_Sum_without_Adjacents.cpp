// Given an array Arr of size N containing positive integers. 
// Find the maximum sum of a subsequence such that no two numbers
// in the sequence should be adjacent in the array.
//
// Example 1:
//
// Input:
// N = 6
// Arr[] = {5, 5, 10, 100, 10, 5}
// Output: 110
// Explanation: If you take indices 0, 3
// and 5, then Arr[0]+Arr[3]+Arr[5] =
// 5+100+5 = 110.
// Example 2:
//
// Input:
// N = 4
// Arr[] = {3, 2, 7, 10}
// Output: 13
// Explanation: 3 and 10 forms a non
// continuous  subsequence with maximum
// sum.

int findMaxSum(int *arr, int n) {
    // code here
    int include = arr[0], exclude = 0;
    int curr = 0;
    for(int i=1; i<n; i++){
        curr = max(include, exclude);
        include = exclude + arr[i];
        exclude = curr;
    }
    return max(include, exclude);
}
