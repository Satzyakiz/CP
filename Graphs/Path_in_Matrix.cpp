// Given a N X N  matrix Matrix[N][N] of positive integers.
// There are only three possible moves from a cell Matrix[r][c].
//
// 1. Matrix[r+1][c]
//
// 2. Matrix[r+1][c-1]
//
// 3. Matrix[r+1][c+1]
//
// Starting from any column in row 0, return the largest sum of any of
// the paths up to row N-1.
//
// Input:
// 1
// 2
// 348 391 618 193
//
// Output:
// 1009
//
// Explanation: In the sample test case, the path leading to maximum
// possible sum is 391->618.  (391 + 618 = 1009)

#include<bits/stdc++.h>
using namespace std;
int dp[30][30];
void DFS(vector<vector<int>> &mat,int i,int j,int sum = 0){
    if(i < 0 || j < 0 || i >= mat.size() || j >= mat.size())
        return;
    sum += mat[i][j];
    if(sum <= dp[i][j])
        return;
    dp[i][j] = max(sum,dp[i][j]);
    DFS(mat,i+1,j,sum);
    DFS(mat,i+1,j-1,sum);
    DFS(mat,i+1,j+1,sum);
}
void solve(){
    int n;
    cin>>n;
    memset(dp, 0, sizeof(dp));
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
    for(int j=0; j<n; j++)
        DFS(mat,0,j);
    int maxVal = dp[n-1][0];
    for(int j=1; j<n; j++)
        maxVal = max(maxVal,dp[n-1][j]);
    cout<<maxVal<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
