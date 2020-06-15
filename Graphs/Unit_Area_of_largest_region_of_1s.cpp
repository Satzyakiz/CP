// Consider a matrix with N rows and M columns, where each cell 
// contains either a ‘0’ or a ‘1’ and any cell containing a 1 is
// called a filled cell. Two cells are said to be connected if they
// are adjacent to each other horizontally, vertically, or diagonally.
// If one or more filled cells are connected, they form a region. The
// task is to find the unit area of the largest region.
// Input:
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 1 3
// 1 1 1
//
// Output:
// 4
// 3
//
// Explanation:
// Testcase 1: Matrix can be shown as follows:
// 1 1 0
// 0 0 1
// 1 0 1
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void helper(vector<vector<int>> &adj,int i,int j,int &count){
    if(i<0||j<0||i>=adj.size()||j>=adj[0].size())
        return;
    if(adj[i][j] == 0)
        return;
    count++;
    adj[i][j] = 0;
    helper(adj,i-1,j,count);
    helper(adj,i+1,j,count);
    helper(adj,i,j-1,count);
    helper(adj,i,j+1,count);
    helper(adj,i-1,j-1,count);
    helper(adj,i+1,j+1,count);
    helper(adj,i-1,j+1,count);
    helper(adj,i+1,j-1,count);

}
void solve(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
    }
    int maxCount = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]){
                int count = 0;
                helper(mat,i,j,count);
                maxCount = max(maxCount,count);
            }
        }
    }
    cout<<maxCount<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
