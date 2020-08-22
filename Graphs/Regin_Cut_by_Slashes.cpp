
// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square
// consists of a /, \, or blank space.  These characters divide
// the square into contiguous regions.
//
// (Note that backslash characters are escaped, so a \ is represented as "\\".)
//
// Return the number of regions.

// Example 1:
//
// Input:
// [
//   " /",
//   "/ "
// ]
// Output: 2
//
// Example 2:
//
// Input:
// [
//   " /",
//   "  "
// ]
// Output: 1
// Example 3:
//
// Input:
// [
//   "\\/",
//   "/\\"
// ]
// Output: 4
// Example 4:
//
// Input:
// [
//   "/\\",
//   "\\/"
// ]
// Output: 5
//
// Example 5:
//
// Input:
// [
//   "//",
//   "/ "
// ]
// Output: 3

void DFS(vector<vector<int>> &mat, int i,int j){
    if(i < 0 || j < 0 || i >= mat.size() || j >= mat[i].size() || mat[i][j] != 0){
        return;
    }
    mat[i][j] = 1;
    DFS(mat,i+1,j);
    DFS(mat,i-1,j);
    DFS(mat,i,j+1);
    DFS(mat,i,j-1);
}
int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> mat(n * 3,vector<int>(n*3,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '/'){
                mat[i*3][j*3+2] = 1;
                mat[i*3+1][j*3+1] = 1;
                mat[i*3+2][j*3] = 1;
            }else if(grid[i][j] == '\\'){
                mat[i*3][j*3] = 1;
                mat[i*3+1][j*3+1] = 1;
                mat[i*3+2][j*3+2] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0; i < 3*n; i++){
        for(int j=0; j < 3*n; j++){
            if(mat[i][j] == 0){
                DFS(mat,i,j);
                ans++;
            }
        }
    }
    return ans;
}
