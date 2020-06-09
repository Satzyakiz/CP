// Given a string s and a string t, check if s is subsequence of t.
//
// A subsequence of a string is a new string which is formed from
// the original string by deleting some (can be none) of the characters
// without disturbing the relative positions of the remaining characters.
// (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
// Example 1:
//
// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:
//
// Input: s = "axc", t = "ahbgdc"
// Output: false

int LCS(string s,string t){
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1; i<= m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string s, string t) {
        return LCS(s,t) == s.size();
    }
