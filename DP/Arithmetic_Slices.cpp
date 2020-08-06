// A sequence of numbers is called arithmetic if it consists of at 
// least three elements and if the difference between any two consecutive
// elements is the same.
//
// For example, these are arithmetic sequences:
//
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
//
// 1, 1, 2, 5, 7



int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if(n < 3)
        return 0;
    vector<int> dp(n);
    if(A[2] - A[1] == A[1] - A[0])
        dp[2] = 1;
    int ans = dp[2];
    for(int i=3; i<n; i++){
        if(A[i] - A[i-1] == A[i-1] - A[i-2])
            dp[i] = dp[i-1] + 1;
        ans += dp[i];
    }
    return ans;
}
