// Given a square grid of size N, each cell of which contains integer
// cost which represents a cost to traverse through that cell, we need
// to find a path from top left cell to bottom right cell by which total
// cost incurred is minimum. You can move in 4 directions : up, down,
// left an right.
//
// Note : It is assumed that negative cost cycles do not exist in input matrix.
// Input:
// 2
// 5
// 31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
// 2
// 42 93 7 14
//
// Output:
// 327
// 63

//DFS -> TLE, so use BFS
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int mat[n][n], dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            dp[i][j] = INT_MAX;
        }
    queue<pair<int,int>> q;
    q.push({0,0});
    int x[4] = {-1,1,0,0},y[4] = {0,0,-1,1};
    dp[0][0] = mat[0][0];
    int tX, tY;
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            tX = a + x[i], tY = b + y[i];
            if(tX >= 0 && tY >= 0 && tX < n &&
               tY < n && dp[tX][tY] > dp[a][b] + mat[tX][tY]){

                    dp[tX][tY] = dp[a][b] + mat[tX][tY];
                    q.push({tX,tY});
            }
        }

    }
    cout<<dp[n-1][n-1]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
