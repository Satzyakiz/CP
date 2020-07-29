// Given a graph, a source vertex in the graph and a number k,
// find if there is a simple path, of path length greater then or
// equal to k,(without any cycle) starting from a given source and
// ending at any other vertex.
// Source vertex should always be  0.
//
// Input:
// 2
// 9 14 60
// 0 1 4 0 7 8 1 2 8 1 7 11 2 3 7 2 5 4 2 8 2 3 4 9 3 5 14 4 5 10 5 6 2 6 7 1 6 8 6 7 8 7
// 4 3 8
// 0 1 5 1 2 1 2 3 1
//
// Output:
// 1
// 0

#include<bits/stdc++.h>
using namespace std;
bool flag;
void check(vector<vector<pair<int,int>>> &adj, int u, int k,vector<bool> &visited){
    if(k <= 0){
        // cout<<"here\n";
        flag = true;
        return;
    }

    visited[u] = true;
    // cout<<k<<endl;
    for(auto &p: adj[u]){
        int v = p.first, w = p.second;
        // cout<<v<<" "<<w<<endl;
        if(!visited[v])
            check(adj,v,k-w,visited);
        if(flag)
            return;
    }

    visited[u] = false;

}
void solve(){
    int V,e,k,u,v,w;
    cin>>V>>e>>k;
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool> visited(V);
    flag = false;
    check(adj,0,k,visited);
    if(flag)
        cout<<"1\n";
    else
        cout<<"0\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
