
// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
// Input:
// 3
// 5 6
// 0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
// 2 2
// 1 1 1 1
// 2 2
// 0 0 0 0
//
// Output:
// 3
// 2
// 0

#include<bits/stdc++.h>
using namespace std;

int getAns(vector<vector<int>> &mat){
    int m = mat.size();
    if(m == 0)
        return 0;
    int n = mat[0].size();

    int maxVal = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1){
                mat[i][j] = 1;
                if(i > 0 && j > 0){
                    mat[i][j] = 1+min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]});
                }
                maxVal = max(maxVal, mat[i][j]);
            }
        }
    }

    return maxVal;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    cout<<getAns(mat)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
