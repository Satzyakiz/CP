// Given a string s, find the longest palindromic subsequence's
// length in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input:
//
// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
//
//
// Example 2:
// Input:
//
// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb"
int LCS(string a,string b){
        int m = a.size(),n = b.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string os = s;
        reverse(s.begin(),s.end());
        return LCS(os,s);
    }
