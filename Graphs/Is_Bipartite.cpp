// Given an undirected graph, return true if and only if it is bipartite.
//
// Example 1:
// Input: [[1,3], [0,2], [1,3], [0,2]]
// Output: true
// Explanation:
// The graph looks like this:
// 0----1
// |    |
// |    |
// 3----2
// We can divide the vertices into two groups: {0, 2} and {1, 3}.
// Example 2:
// Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
// Output: false
// Explanation:
// The graph looks like this:
// 0----1
// | \  |
// |  \ |
// 3----2
// We cannot find a way to divide the set of nodes into two independent subsets.

bool valid(vector<vector<int>> &graph,vector<int> &colors,
            int color,int index){
    if(colors[index] != 0)
        return colors[index] == color;
    colors[index] = color;
    for(int next : graph[index]){
        if(!valid(graph,colors,-color,next))
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> colors(n,0);
    for(int i=0; i<graph.size(); i++){
        if(colors[i] == 0 && !valid(graph,colors,1,i))
            return false;
    }
    return true;
}
