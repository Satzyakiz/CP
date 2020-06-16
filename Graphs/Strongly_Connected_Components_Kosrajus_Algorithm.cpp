
// Given a graph with N nodes and M directed edges. Your task is to complete 
// the function kosaraju() which returns an integer denoting the number of
// strongly connected components in the graph.
// Expected Time Complexity: O(N + M).
// Expected Auxiliary Space: O(N).
// Input:
// 2
// 5 5
// 1 0 0 2 2 1 0 3 3 4
// 3 3
// 0 1 1 2 2 0
//
// Output:
// 3
// 1

vector<vector<int>> transpose(vector<int> adj[],int V){
    vector<vector<int>> nAdj(V);
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            nAdj[adj[i][j]].emplace_back(i);
        }
    }
    return nAdj;
}
void dfs(int index,vector<bool> &visited,stack<int> &s,vector<int> adj[]){
    visited[index] = true;
    for(int j=0; j<adj[index].size(); j++){
        if(!visited[adj[index][j]]){
            dfs(adj[index][j],visited,s,adj);
        }
    }
    s.push(index);
}
void dfsStrong(int index,vector<bool> &visited,vector<vector<int>> adj){
    visited[index] = true;
    for(int j=0; j<adj[index].size(); j++){
        if(!visited[adj[index][j]])
            dfsStrong(adj[index][j],visited,adj);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here

    stack<int> s;
    vector<bool> visited(V,false);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(i,visited,s,adj);
        }
    }
    // for(int i=0; i<V; i++) visited[i] = false;
    vector<bool> nVisited(V,false);
    int count = 0;
    vector<vector<int>> tAdj = transpose(adj,V);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!nVisited[v]){
            dfsStrong(v,nVisited,tAdj);
            count++;
        }
    }
    return count;
}
