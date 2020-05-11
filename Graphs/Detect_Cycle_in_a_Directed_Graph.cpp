// VISITED ARRAY KEEPS COUNT WHICH VERTICES ARE VISITED
// REC ARRAY KEEPS COUNT WHETHER IN A PARTICULAR DFS, A CYCLE IS FOUND OR NOT
// IF NO CYCLE FORMS, THE REC IS ASSIGNED FALSE AGAIN (BACKTRACKING)

bool cycle(vector<vector<int>> adj,int ind,vector<bool> &visited,vector<bool> &rec){
  visited[ind] = true;
  rec[ind] = true;
  for(int i=0; i < adj[ind].size(); i++){
    int t = adj[ind][i];
    if(!visited[t] && cycle(adj,t,visited,rec))
      return true;
    else if(rec[t] == true)
      return true;
  }
  rec[ind] = false;
  return false;
}

bool isCyclic(vector<vector<int>> adj,int V){ // V : no of vertices
  vector<bool> visited(V,false);
  vector<bool> rec(V,false);
  for(int i=0; i<adj.size(); i++){
    if(!visited[i] && cycle(adj,i,visited,rec))
      return true;
  }
  return false
}
