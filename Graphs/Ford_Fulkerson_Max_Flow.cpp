// Given a graph with N vertices numbered 1 to N and M edges, the task 
// is to find the max flow from vertex 1 to vertex N.
// Input:
// 2
// 5 4
// 1 2 1 3 2 2 4 2 3 2 5 5
// 4 4
// 1 2 8 1 3 10 2 4 2 3 4 3
// Output:
// 1
// 5

#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &g, int s,int t,vector<int> &parent){
    vector<bool> visited(g.size());
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1; v < g.size(); v++){
            if(!visited[v] && g[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int FordFulkerson(vector<vector<int>> &graph, int s, int e){
    int u,v;
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(graph.size());
    int maxFlow = 0;
    while(BFS(residualGraph,s,e,parent)){
        int pathFlow = INT_MAX;
        for(v = e; v != s; v = parent[v]){
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for(v = e; v != s; v = parent[v]){
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }

    return maxFlow;
}
void solve(){
    int V,e,x,y,z;
    cin>>V>>e;
    vector<vector<int>> graph(V+1,vector<int>(V+1));
    for(int i=0; i<e; i++){
        cin>>x>>y>>z;
        graph[x][y] += z;
        graph[y][x] += z;
    }

    cout<<FordFulkerson(graph,1,V)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
