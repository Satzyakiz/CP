// Example 1:
//
// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:
//
// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:
//
// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false

//USING BFS
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
  vector<vector<int>> adjMat(N+1); //Adjacency Matrix
  for(auto d: dislikes){
    adjMat[d[0]].emplace_back(d[1]);
    adjMat[d[1]].emplace_back(d[0]);
  }

  vector<int> color(N+1,0);
  vector<bool> visited(N+1,false);
  queue<int> q;

  //Color can be between 1 or 2, as the graph is Bipartite.
  for(int i=1; i<N+1; i++){
    if(!visited[i]){ //If that node is not yet visited
      q.push(i);
      color[i] = 1;
      while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(int v: adjMat[u]){
          if(color[v] == color[u])
            return false;
          if(color[u] == 1)
            color[v] = 2;
          else
            color[v] = 1;
          q.push(v);
        }
      }
    }
  }
  return true;
}
