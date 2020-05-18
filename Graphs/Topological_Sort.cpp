//Topological Sort can only be one on a Directed Acyclic Graph
//Modified DFS is used
// Topological sorting for Directed Acyclic Graph (DAG)
// is a linear ordering of vertices such that for every directed edge uv,
// vertex u comes before v in the ordering.

void doTopologicalSort(int i,vector<bool> &visited,stack<int> stk,vector<vector<int>> adj){
  visited[i] = true;
  for(int j=0; j<adj[i].size(); j++){
    if(!visited[adj[i][j]]){
      doTopologicalSort(adj[i][j],visited,stk,adj);
    }
  }
  stk.push(i);
}

vector<int> topsort(vector<vector<int>> adj){ //adj: adjacency matrix
  int V = adj.size(); //no of vertices
  vector<bool> visited(V,false);
  stack<int> stk;
  for(int i=0; i<V; i++){
    if(!visited[i])
      doTopologicalSort(i,visited,stk,adj);
  }
  vector<int> ans(V);
  for(int i=0; i<V; i++){
    ans[i] = stk.top();
    stk.pop();
  }
  return ans;
}
