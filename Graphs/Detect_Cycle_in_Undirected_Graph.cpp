// Given a Undirected Graph. Check whether it contains a cycle or not.
// Input:
// 3
// 2 1
// 0 1
// 4 3
// 0 1 1 2 2 3
// 5 4
// 0 1 2 3 3 4 4 2
//
// Output:
// 0
// 0
// 1
bool check(int u,vector<int> g[],int V,vector<bool> &visited,int parent){
    visited[u] = true;
    for(int i=0; i<g[u].size(); i++){
        if(visited[g[u][i]] == false){
            if(check(g[u][i],g,V,visited,u))
                return true;
        }
        else if(g[u][i] != parent)
            return true;
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   vector<bool> visited(V,false);
   for(int i=0; i<V; i++){
       if(visited[i] == false){
           if(check(i,g,V,visited,-1))
                return true;
       }
   }
   return false; 
}
