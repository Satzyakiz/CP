// Given an array A of integers, return true if and only if we can
// partition the array into three non-empty parts with equal sums.
//
// Formally, we can partition the array if we can find indexes
// i+1 < j with
// (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] +
// ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
//
//
//
// Example 1:
//
// Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
// Output: true
// Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
// Example 2:
//
// Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
// Output: false
// Example 3:
//
// Input: A = [3,3,6,5,-2,2,5,1,-9,4]
// Output: true
// Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4

bool canThreePartsEqualSum(vector<int>& A) {
    int sum = 0;
    for(int &x: A)
        sum += x;
    if(sum % 3)
        return 0;
    sum /= 3;
    int ans = 0, x = 0,curr = 0;
    for(int i=0; i<A.size()-1; i++){
        curr += A[i];
        if(curr == 2 * sum && i > 0)
            ans += x;
        if(curr == sum)
            x++;
    }
    return ans;
}
