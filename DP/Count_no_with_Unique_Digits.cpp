
// Given a non-negative integer n, count all numbers with unique digits, 
// x, where 0 ≤ x < 10n.
//
// Example:
//
// Input: 2
// Output: 91
// Explanation: The answer should be the total numbers in the
// range of 0 ≤ x < 100,
//              excluding 11,22,33,44,55,66,77,88,99


int countNumbersWithUniqueDigits(int n) {
    if(n > 10)
        return 0;
    if(n == 0)
        return 1;
    vector<int> dp(n+1);
    int k = 9;
    dp[0] = 1, dp[1] = 9;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] * k;
        k--;
    }
    int ans = 0;
    for(int &s: dp)
        ans += s;
    return ans;
}
