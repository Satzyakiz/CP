
// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right,
// up or down. You may NOT move diagonally or move outside of the boundary
// (i.e. wrap-around is not allowed).
//
// Example 1:
//
// Input: nums =
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:
//
// Input: nums =
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. 
// Moving diagonally is not allowed.


int DFS(vector<vector<int>>& matrix, int i, int j, int val, vector<vector<int>> &dp){
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size() || matrix[i][j] <= val)
        return 0;
    if(dp[i][j] != 0)
        return dp[i][j];
    int U = DFS(matrix,i-1,j,matrix[i][j],dp) + 1;
    int D = DFS(matrix,i+1,j,matrix[i][j],dp) + 1;
    int L = DFS(matrix,i,j-1,matrix[i][j],dp) + 1;
    int R = DFS(matrix,i,j+1,matrix[i][j],dp) + 1;

    return dp[i][j] = max(U, max(D, max(L,R)));
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    int ans = 0, m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, DFS(matrix,i,j,INT_MIN,dp));
        }
    }
    return ans;
}
