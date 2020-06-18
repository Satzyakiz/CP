  int find(vector<int> &parent,int x){
        if(x != parent[x]){
            parent[x] = find(parent,parent[x]);
        }
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int par_u = find(parent,u), par_v = find(parent,v);
            if(par_u == par_v) // It implies that a cycle is detected
                return e;
            else
                parent[par_u] = par_v;
        }
        return {};
    }
