// Give a N*N square matrix, return an array of its anti-diagonals.
// Look at the example for more details.
//
// For Example:
// If the matrix is
//
// 1 2 3
// 4 5 6
// 7 8 9
// The output should Return the following :
//
// [
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]
// i.e print the elements of array diagonally.

#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    map<int,vector<int>> um;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            um[i+j].push_back(mat[i][j]);
        }
    for(auto i = um.begin(); i != um.end(); i++){
        for(auto ele = i->second.begin(); ele != i->second.end(); ele++){
            cout<<*ele<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
