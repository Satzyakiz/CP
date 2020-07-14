// Given a string S and a string T, count the number of distinct
// subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the
// original string by deleting some (can be none) of the characters without
// disturbing the relative positions of the remaining characters.
// (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

int LCS_Modified(string s,string t){
    int m = s.size(), n = t.size();
    vector<vector<long long>> dp(m+1,vector<long long>(n+1));
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else if(i == 0){
                dp[i][j] = 0;
            }else if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            // dp[i-1][j] indicates: leave the character of the string s
            // dp[i-1][j-1] indicates: consider the character of the string s
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[m][n];
}
int numDistinct(string s, string t) {
    return LCS_Modified(s,t);
}
