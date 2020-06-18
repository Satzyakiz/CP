// All pair shortest path problem
// The problem is to find shortest distances between every pair
// of vertices in a given edge weighted directed Graph. The Graph is
// represented as Adjancency Matrix, and the Matrix denotes the
// weight of the edegs (if it exists) else INF (1e7).
// Input
// 2
// 2
// 0 25
// INF 0
// 3
// 0 1 43
// 1 0 6
// INF INF 0
//
// Output
// 0 25
// INF 0
// 0 1 7
// 1 0 6
// INF INF 0

#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 10000000)
                    cout<<"INF ";
                else
                    cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
