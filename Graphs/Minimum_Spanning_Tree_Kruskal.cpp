// Given a weighted, undirected and connected graph.
// The task is to find the sum of weights of the edges of
// the Minimum Spanning Tree.

// Input:
// 2
// 3 3
// 1 2 5 2 3 3 1 3 1
// 2 1
// 1 2 5
//
// Output:
// 4
// 5
#define pi pair<int,pair<int,int>>
int find(vector<int> &parent,int x){
    if(x != parent[x])
        parent[x] = find(parent,parent[x]);
    return parent[x];
}
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    vector<int> parent(V+1);
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    for(int i=0; i<graph.size(); i++){
        for(int j=i+1; j<graph[i].size(); j++){
            // cout<<graph[i][j]<<" ";
            if(graph[i][j] != INT_MAX){
                // cout<<graph[i][j]<<"  "<<i+1<<"  "<<j+1<<endl;
                pair<int,int> p = make_pair(i+1,j+1);
                pq.push({graph[i][j],p});
            }
        }
    }
    int ans = 0;
    while(!pq.empty()){
        int weight = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        // cout<<weight<<"  "<<x<<"  "<<y<<endl;
        int pX = find(parent,x), pY = find(parent,y);
        if( pX == pY ){

        }
        else{
            parent[pX] = pY;
            ans += weight;
        }
    }
    return ans;
}
