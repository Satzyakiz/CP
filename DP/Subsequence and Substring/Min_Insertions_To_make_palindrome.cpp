
// Example 1:
//
// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we don't
// need any insertions.
// Example 2:
//
// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:
//
// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

int LCS(string A,string B){
    int n1 = A.size(), n2 = B.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1; i<n1+1; i++){
        for(int j=1; j<n2+1; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

    int minInsertions(string A) {
        string B = A;
        reverse(B.begin(),B.end());
        return A.size() - LCS(A,B);
    }
