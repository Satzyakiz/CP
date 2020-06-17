// Given a Matrix consisting of 0s and 1s. Find the number of islands
// of connected 1s present in the matrix.
// Note: A 1 is said to be connected if it has another 1 around
// it (either of the 8 directions).
// Input
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 4 4
// 1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0
//
// Output
// 2
// 2
//
// Explanation:
// Testcase 1: The graph will look like
// 1 1 0
// 0 0 1
// 1 0 1
// Here, two islands will be formed

void helper(vector<vector<int>> &adj,int i,int j){
    if(i<0||j<0||i>=adj.size()||j>=adj[0].size())
        return;
    if(adj[i][j] == 0)
        return;
    adj[i][j] = 0;
    helper(adj,i-1,j);
    helper(adj,i+1,j);
    helper(adj,i,j-1);
    helper(adj,i,j+1);
    helper(adj,i-1,j-1);
    helper(adj,i+1,j+1);
    helper(adj,i-1,j+1);
    helper(adj,i+1,j-1);

}
int findIslands(vector<int> A[], int N, int M) {
    // Your code here
    int m,n;
    m = N, n = M;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            mat[i][j] = A[i][j];
    }
    int maxCount = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]){
                maxCount++;
                helper(mat,i,j);
            }
        }
    }
    return maxCount;
}
