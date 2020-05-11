//Basic Implementation of BFS using queue
//If there is a connection with ith value, the value is present in g[i] in matrix.
void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(vis[t] == false){
            for(int i=0; i<g[t].size(); i++){
                if(g[t][i]){
                    q.push(g[t][i]);
                }
            }
            cout<<t<<" ";
            vis[t] = true;
        }
    }
}
