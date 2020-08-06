


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
