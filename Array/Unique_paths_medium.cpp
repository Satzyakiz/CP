// A robot is located at the top-left corner of a m x n
// grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid
// (marked 'Finish' in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many
// unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        int flag = 0;
        for(int i=0; i<m; i++){
            if(!obstacleGrid[i][0]){
                if(flag){
                    dp[i][0] = 0;
                }
                else{
                    dp[i][0] = 1;
                }
            }
            else{
                flag = 1;
                dp[i][0] = 0;
            }
        }
        flag = 0;
        for(int j=0; j<n; j++){
            if(!obstacleGrid[0][j]){
                if(flag){
                    dp[0][j] = 0;
                }
                else{
                    dp[0][j] = 1;
                }
            }
            else{
                flag = 1;
                dp[0][j] = 0;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
