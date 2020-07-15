// Given an array A of positive integers (not necessarily distinct),
// return the lexicographically largest permutation that is smaller than A,
// that can be made with one swap (A swap exchanges the positions of
// two numbers A[i] and A[j]).  If it cannot be done, then return the same array.
//
// Example 1:
//
// Input: [3,2,1]
// Output: [3,1,2]
// Explanation: Swapping 2 and 1.
// Example 2:
//
// Input: [1,1,5]
// Output: [1,1,5]
// Explanation: This is already the smallest permutation.
// Example 3:
//
// Input: [1,9,4,6,7]
// Output: [1,7,4,6,9]
// Explanation: Swapping 9 and 7.
// Example 4:
//
// Input: [3,1,1,3]
// Output: [1,3,1,3]
// Explanation: Swapping 1 and 3.

bool check(vector<int> &A){
    for(int i=1; i<A.size(); i++){
        if(A[i] < A[i-1])
            return false;
    }
    return true;
}
void helper(vector<int> &A){
    int n = A.size(), i = n-2;
    while(i >= 0 && A[i] <= A[i+1])
        i--;
    int maxItem = A[i+1],maxIndex = i+1;
    for(int j=i+1; j<n; j++){
        if(A[j] < A[i]){
            if(A[j] > maxItem){
                maxItem = A[j];
                maxIndex = j;
            }
        }
    }
    swap(A[i],A[maxIndex]);
}
vector<int> prevPermOpt1(vector<int>& A) {
    if(check(A)){
        return A;
    }
    helper(A);
    return A;
}
