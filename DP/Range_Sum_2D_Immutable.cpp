// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12

vector<vector<int>> sum;
NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(),n;
    if(m == 0)
        n = 0;
    else
        n =matrix[0].size();
    vector<vector<int>> mat(m+1,vector<int>(n+1));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            mat[i][j] = matrix[i-1][j-1] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    sum = mat;
}

int sumRegion(int row1, int col1, int row2, int col2) {
    return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
}
