// Given a NxN matrix of positive integers. There are only three possible
// moves from a cell Matrix[r][c].
//
// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// ​Starting from any column in row 0, return the largest sum of any of the
// paths up to row N-1.
//
//
// Example 1:
//
// Input: N = 2
// Matrix = {{348, 391},
//           {618, 193}}
// Output: 1009
// Explaination: The best path is 391 -> 618.
// It gives the sum = 1009.
//
// Example 2:
//
// Input: N = 2
// Matrix = {{2, 2},
//           {2, 2}}
// Output: 4
// Explaination: No matter which path is
// chosen, the output is 4.

int dp[101][101];
    int size;
    int helper(int i,int j, vector<vector<int>> &mat){
        if(j < 0 || j >= size || i >= size)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int left = helper(i+1,j-1,mat);
        int center = helper(i+1,j,mat);
        int right = helper(i+1,j+1,mat);
        return dp[i][j] = mat[i][j] + max(left, max(center, right));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        size = N;
        memset(dp, -1, sizeof(dp));
        int maxVal = 0;
        for(int i=0; i<N; i++)
            maxVal = max(maxVal, helper(0,i,Matrix));
        return maxVal;

    }
