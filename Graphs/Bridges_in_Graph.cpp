
int time;
void bridgeUtil(vector<vector<int>> &adj, int u, vector<int> &visited,
                vector<int> &low,vector<int> &discovered,
                vector<int> parent, vector<vector<int>> &ans){

    visited[u] = true;
    low[u] = discovered[u] = ++time;

    for(int &v: adj[u]){
        if(visited[v] == 0){
            parent[v] = u;
            bridgeUtil(adj,v,visited,low,discovered, parent,ans);
            low[u] = min(low[u], low[v]);
            if(low[u] > discovered[v]){
                ans.push_back({u,v});
            }

        }else if( v != parent[u]){
            low[u] = min(low[u], discovered[v]);
        }
    }

}
void bridge(vector<vector<int>> &adj){
        vector<vector<int>> ans;
        int V = adj.size();
        time = 0;
        vector<int> visited(V,0), low(V), discovered(V),
                    parent(V,-1);
        for(int i=1; i<V; i++){
            if(visited[i] == 0)
                bridgeUtil(adj, i, visited, low, discovered, parent, ans);
        }
        printBridgeEdges(ans);
}
