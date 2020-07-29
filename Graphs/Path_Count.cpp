Given a directed graph and two vertices source and destination, your
task is to complete the function countPaths(), whose function is to
count the total number of ways or paths that exist between two vertices
in a directed graph.
The Graph may be disconnected or may contain cycles, but the paths
should not contain cycles.

Input:
1
4 5
0 1 0 3 2 0 2 1 1 3
2 3

Output:
3

int val;
void ways(int s, int d, vector<bool> &visited){
    if(s == d){
        val++;
        return;
    }
    visited[s] = true;
    for(int &v: adj[s]){
        if(!visited[v])
            ways(v,d,visited);
    }
    visited[s] = false;
}
int countPaths(int s, int d)
{
    // Code here
    val = 0;
    vector<bool> visited(V);
    ways(s,d,visited);
    return val;
}
