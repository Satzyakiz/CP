// Count the total number of ways or paths that exist between two vertices
// in a directed graph. These paths doesn’t contain a cycle.
//
// Input:
// 1
// 5 7
// 1 2 1 3 1 5 2 4 2 5 3 5 4 3
// 1 5
// Output:
// 4
//
// Explanation:
// Testcase 1 :  There are 4 paths from 1 to 5.
//                        1 -> 5
//                        1 -> 2 -> 5
//                        1 -> 3 -> 5
//                        1 -> 2 -> 4 -> 3 -> 5

#include<bits/stdc++.h>
using namespace std;
int countV;
void ways(vector<vector<int>> &adj, int s, int e,vector<int> &visited){
    if(s == e){
        countV++;
        return;
    }
    visited[s] = 1;
    for(int &v: adj[s]){
        if(!visited[v])
            ways(adj,v,e,visited);
    }
    visited[s] = 0;
}
void solve(){
    int  V,e,x,y;
    cin>>V>>e;
    vector<vector<int>> adj(V+1);
    for(int i=0; i<e; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cin>>x>>y;
    countV = 0;
    vector<int> visited(V+1);
    ways(adj,x,y,visited);
    cout<<countV<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
