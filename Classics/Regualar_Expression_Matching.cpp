
// Given an input string (s) and a pattern (p), implement regular
// expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
// Example 1:
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:
//
// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:
//
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:
//
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
// Example 5:
//
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false

// Recursive Approach
bool isMatch(string s, string p) {
    return isMatch(0,s,0,p);
}
bool isMatch(int i, string& s, int j, string &p) {
    int pn=p.size(), sn = s.size();
    if(j == pn)
        return i==sn;
    if(p[j+1]=='*') {
        if(isMatch(i,s,j+2,p))
            return 1;
        while(i<sn && (p[j]==s[i]||p[j]=='.'))
            if(isMatch(++i,s,j+2,p))
                return 1;
    } else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch(i+1,s,j+1,p))
        return 1;
    return 0;
}

//DP Memoization
bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
    return match(0,s,0,p,dp);
}
bool match(int i,string s,int j,string p,vector<vector<int>> &dp){
    if(dp[i][j] != -1)
        return dp[i][j];
    int n1 = s.size(), n2 = p.size();
    if(j == n2)
        return dp[i][j] = i == n1;

    if(p[j+1] == '*'){
        if(match(i,s,j+2,p,dp))
            return dp[i][j] = true;
        while(i < n1 && (s[i] == p[j] || p[j] == '.')){
            if(match(++i,s,j+2,p,dp))
                return dp[i][j] = true;
        }
    }else if(i < n1 && (p[j] == '.' || s[i] == p[j]) && match(i+1,s,j+1,p,dp)){
        return dp[i][j] = true;
    }
    return dp[i][j] = false;
}
