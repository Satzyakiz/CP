// Check_if_negetive_weight_cycle_present
// Given a graph, the task is to check if it contains a
// negative weight cycle or not.
// Input:
// 2
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// 3 3
// 0 1 -5 1 2 -6 2 0 -9
// Output:
// 0
// 1

#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u,v,w;
        Edge(int x,int y,int z){
            u = x;
            v = y;
            w = z;
        }
};
void solve(){
    int V,E,x,y,z;
    cin>>V>>E;
    // vector<vector<int>> adj(V,vector<int>(V));
    vector<Edge> adj;
    for(int i=0; i<E; i++){
        cin>>x>>y>>z;
        Edge e(x,y,z);
        adj.emplace_back(e);
    }
    vector<int> dist(V,INT_MAX);
    dist[0] = 0;
    for(int i=1; i<V; i++){
        for(int j=0; j<E; j++){
            int u = adj[j].u;
            int v = adj[j].v;
            int w = adj[j].w;
            if(dist[u] != INT_MAX && dist[u]+w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(int j=0; j<E; j++){
        int u = adj[j].u;
        int v = adj[j].v;
        int w = adj[j].w;
        //The below line signifies that negetive weight cycles are present
        if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
            cout<<"1\n";
            return;
        }
    }
    cout<<"0\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
