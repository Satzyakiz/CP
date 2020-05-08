// Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right which minimizes the
// sum of all numbers along its path.
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c));
        dp[0][0] = grid[0][0];

        //initialize the first row
        for(int j=1; j<c; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        //initialize the first column
        for(int i=1; i<r; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        //initialize the rest of the matrix
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        //print the new distances
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }

        return dp[r-1][c-1];
    }
