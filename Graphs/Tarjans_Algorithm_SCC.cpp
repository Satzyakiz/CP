// Given an unweighted directed graph, your task is to print
// the members of the strongly connected component in the graph
// where each component is separated by ', ' (see the example for more clarity).
// The Graph can have loops.

// Input:
// 2
// 3 3
// 1 2 2 0 2 2
// 4 3
// 1 2 2 3 3 1
// Output:
// 0,2,1,
// 0,3 2 1,

#include<bits/stdc++.h>
using namespace std;

int timeVal;

void dfs(vector<vector<int>> &adj,int u,vector<int> &low,vector<int> &disc,
        vector<bool> &stackMember,stack<int> &stk){

    low[u] = disc[u] = ++timeVal;
    stk.push(u);
    stackMember[u] = true;

    for(int j=0; j<adj[u].size(); j++){
        int v = adj[u][j];
        if(disc[v] == -1){
            dfs(adj,v,low,disc,stackMember,stk);
            low[u] = min(low[u],low[v]);
        }else if(stackMember[v] == true){
            low[u] = min(low[u],disc[v]);
        }
    }

    int w = 0;
    if(low[u] == disc[u]){
        while(stk.top() != u){
            w = stk.top();
            stk.pop();
            stackMember[w] = false;
            cout<<w<<" ";
        }
        w = stk.top();
        cout << w << ",";
        stackMember[w] = false;
        stk.pop();
    }

}

void tarjan(vector<vector<int>> &adj){
    timeVal = 0;
    int n = adj.size();
    vector<int> low(n,-1),disc(n,-1);
    vector<bool> stackMember(n,false);
    stack<int> stk;

    for(int i=0; i<n; i++){
        if(disc[i] == -1)
            dfs(adj,i,low,disc,stackMember,stk);
    }
    cout<<endl;
}
void solve(){
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].emplace_back(v);
    }

    tarjan(adj);
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
