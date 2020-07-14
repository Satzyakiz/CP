// Given a string s, partition s such that every substring
// of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced
// using 1 cut.

class Solution {
public:

    bool isPal(string s,int i,int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++, j--;
        }

        return true;
    }
    int getMinCut(string s,int i,int j,vector<vector<int>> &dp){
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        if(isPal(s,i,j))
            return 0;
        int left,right;
        int minVal = INT_MAX;
        for(int k=i; k<j; k++){
            if(dp[i][k] != -1){
                left = dp[i][k];
            }else{
                left = getMinCut(s,i,k,dp);
                dp[i][k] = left;
            }
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }else{
                right = getMinCut(s,k+1,j,dp);
                dp[k+1][j] = right;
            }
            int temp = left+right+1;
            minVal = min(minVal,temp);
        }
        return dp[i][j] = minVal;

    }
    int minCut(string s) {
        int n = s.size();
        if(isPal(s,0,n-1))
            return 0;
        for(int i=1;i<n;i++)
        {
            string s1 = s.substr(0,i);
            string s2(s1);
            reverse(s2.begin(),s2.end());

            string s3 = s.substr(i);
            string s4(s3);
            reverse(s4.begin(),s4.end());
            if(s1==s2 && s3==s4)
                return 1;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return getMinCut(s,0,n-1,dp);
    }
};


//Better Solution
int minCut(string s) {
  vector<int> dp(s.size() + 1);
  iota(begin(dp), end(dp), 0);
  for (int m = 0; m < s.size(); ++m) {
    for (int i = m, j = m + 1; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j)
        dp[j + 1] = min(dp[j + 1], 1 + dp[i]);
    for (int i = m, j = m; i >= 0 && j < s.size() && s[i] == s[j]; --i, ++j)
        dp[j + 1] = min(dp[j + 1], 1 + dp[i]);
  }
  return dp[s.size()] - 1;
}
