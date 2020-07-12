
// Example 1:
//
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]
// Example 2:
//
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]

//Trick:
// Sum of block in matrix: (from (i+k,j+k) to (i-k,j-k))
// sum[i+k,j+k] - sum[i+k,j-k-1] - sum[i-k-1,j+k] + sum[i-k-1,j-k-1]
// In a matrix of size(4x4):
// sum of block from (2,2) to (3,3):
// sum[3,3] - sum[3,1] - sum[1,3] + sum[1,1]

int get(vector<vector<int>> &mat,int i, int j){
    if(i < 0 || j < 0)
        return 0;
    if(i >= mat.size())
        i = mat.size()-1;
    if(j >= mat[0].size())
        j = mat[0].size()-1;

    return mat[i][j];
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    if(m == 0) return {{}};
    int n = mat[0].size();

    vector<vector<int>> dp(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = mat[i][j] + get(dp,i-1,j) + get(dp,i,j-1)
                       - get(dp,i-1,j-1);
        }
    }
    
    vector<vector<int>> ans(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = get(dp,i+k,j+k) - get(dp,i+k, j-k-1)
                        - get(dp,i-k-1,j+k) + get(dp,i-k-1,j-k-1);
        }
    }

    return ans;
}
