Kamar-taj is a place where "The Acient One" trains people to protect earth
from other dimensions.The earth is protected by 'n' sanctums, destroying
any of it will lead to invasion on earth.
The sanctums are connected by 'm' bridges.
Now , you being on dormammu's side , want to finds no of sanctum
destroying which will disconnect the sanctums.

Input:
1
5 5
1 2
1 3
3 2
3 4
5 4

Output:
2

#include<bits/stdc++.h>
using namespace std;
int timee;
void APUtil(vector<vector<int>> &adj, int u, vector<int> &visited,
            vector<int> &low, vector<int> &discovered,
            vector<int> &parent, vector<int> &ap){
        // cout<<u<<endl;
        int children = 0;
        visited[u] = 1;
        low[u] = discovered[u] = ++timee;

        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            // cout<<v<<endl;
            if(visited[v] == 0){
                children++;
                parent[v] = u;
                APUtil(adj, v, visited,low,discovered,parent,ap);
                low[u] = min(low[u], low[v]);
                //Root vertex which have more than 2 children that are not
                // connected by any other means
                if(parent[u] == -1 && children > 1)
                    ap[u] = 1;

                else if(parent[u] != -1 && low[v] >= discovered[u])
                    ap[u] = 1;

            }else if(v != parent[u]){
                low[u] = min(low[u], discovered[v]);
            }
        }
        // cout<<"end\n";

}

int ArticulationPoints(vector<vector<int>> &adj){
    int V = adj.size();
    vector<int> visited(V,0), low(V),
                ap(V,0), discovered(V),
                parent(V,-1);

    for(int i=1; i<V; i++){
        if(visited[i] == 0)
            APUtil(adj, i, visited, low, discovered, parent, ap);
    }
    int count = 0;
    for(int i=0; i<ap.size(); i++){
        int x = ap[i];
        if(x == 1)
            count++;
    }
    return count;
}
void solve(){
    int V,e;
    cin>>V>>e;
    vector<vector<int>> adj(V+1);
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cout<<"Here\n";
    timee = 0;
    cout<<ArticulationPoints(adj)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
