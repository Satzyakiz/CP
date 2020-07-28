// Given an undirected graph and an edge, the task is to find if the given
// edge is a bridge in graph, i.e., removing the edge disconnects the graph.
//
// Input:
// 2
// 4 3
// 0 1 1 2 2 3
// 1 2
// 5 5
// 1 2 2 0 1 0 3 4 3 0
// 2 0
//
// Output:
// 1
// 0

//After removing the edge just check if the end vertex can be visited
void DFS(list<int> adj[], vector<bool> &visited,int s){
    visited[s] = true;
    for(int u: adj[s]){
        if(!visited[u]){
            DFS(adj,visited,u);
        }
    }
}
bool isBridge(list<int> adj[], int V, int s, int e) {
    // Code here
    adj[s].remove(e);
    adj[e].remove(s);
    vector<bool> visited(V,false);
    DFS(adj,visited,s);
    if(visited[e] == false)
        return true;
    else
        return false;
}
