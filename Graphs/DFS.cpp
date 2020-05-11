//Basic Implementation of DFS using queue
//If there is a connection with ith value, the value is present in g[i] in matrix.
void dfs(int s, vector<int> g[], bool vis[])
{

    if(vis[s] == false){
        cout<<s<<" ";
        vis[s] = true;
        for(int i=0; i<g[s].size(); i++){
            if(g[s][i] != 0){
                dfs(g[s][i],g,vis);
            }
        }
    }
    else{
        return;
    }

}
