// Given an 1D integer array A of length N, find the length of
// longest subsequence which is first increasing then decreasing.
//
// Example Input
// Input 1:
//
//  A = [1, 2, 1]
// Input 2:
//
//  A = [1, 11, 2, 10, 4, 5, 2, 1]
//
//
// Example Output
// Output 1:
//
//  3
// Output 2:
//
//  6
//
//
// Example Explanation
// Explanation 1:
//
//  [1, 2, 1] is the longest subsequence.
// Explanation 2:
//
//  [1 2 10 4 2 1] is the longest subsequence.

int longestSubsequenceLength(const vector<int> &A) {

    int n = A.size();
    if(n == 0)
        return 0;
    vector<int> llis(n,1), rlis(n,1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i] && llis[i] < 1 + llis[j]){
                llis[i] = 1 + llis[j];
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j > i; j--){
            if(A[j] < A[i] && rlis[i] < 1 + rlis[j]){
                rlis[i] = 1 + rlis[j];
            }
        }
    }

    int ans = llis[0] + rlis[0] - 1;
    for(int i=1; i<n; i++){
        int temp = llis[i] + rlis[i] - 1;
        ans = max(ans, temp);
    }

    return ans;
}
