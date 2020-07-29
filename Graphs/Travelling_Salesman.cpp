
// Given a matrix M of size N where M[i][j] denotes the cost
// of moving from city i to city j. Your task is to complete a
// tour from the city 0 (0 based index) to all other cities
// such that you visit each city atmost once and then at the
// end come back to city 0 in min cost.
//
// Input:
// 2
// 2
// 0 111
// 112 0
// 3
// 0 1000 5000
// 5000 0 1000
// 1000  5000  0
// Output:
// 223
// 3000



#include<bits/stdc++.h>
using namespace std;
void travel(vector<vector<int>> &mat, vector<bool> &visited,
            int vertexCount, int curr,int pathSum, int &ans){
    if(vertexCount == mat.size() && mat[curr][0]){
        pathSum += mat[curr][0];
        ans = min(ans,pathSum);
        return;
    }
    for(int i=1; i<mat.size(); i++){
        if(!visited[i] && mat[curr][i]){
            visited[i] = true;
            travel(mat,visited,vertexCount+1,i,pathSum + mat[curr][i],ans);
            visited[i] = false;

        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
    vector<bool> visited(n);
    int pathSum = 0, ans = INT_MAX;
    visited[0] = true;
    travel(mat,visited,1,0,pathSum,ans);
    cout<<ans<<endl;
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
