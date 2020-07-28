// A Hamiltonian path, is a path in an undirected or directed graph that 
// visits each vertex exactly once. Given an undirected graph  the task is
// to check if a Hamiltonian path is present in it or not.
//
// Input:
// 2
// 4 4
// 1 2 2 3 3 4 2 4
// 4 3
// 1 2 2 3 2 4
// Output:
// 1
// 0

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj,int u,vector<bool> &visited,
         vector<int> &store, bool &flag){

        if(visited[u]) return;
        visited[u] = true;
        store.emplace_back(u);
        for(int &v: adj[u]){
            if(visited[v] == false){
                DFS(adj,v,visited,store,flag);
            }
        }
        if(store.size() == adj.size() - 1)
            flag = true;
        store.pop_back();
        visited[u] = false;

}

bool HamiltonianPath(vector<vector<int>> &adj){
    int V = adj.size();
    bool flag = false;
    for(int i=1; i<V; i++){
        vector<bool> visited(V,false);
        vector<int> store;
        DFS(adj,i,visited,store,flag);
        if(flag)
            return true;
    }
    return false;
}
void solve(){
    int V,e,u,v;
    cin>>V>>e;
    vector<vector<int>> adj(V+1);
    for(int i=0; i<e; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<HamiltonianPath(adj)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
