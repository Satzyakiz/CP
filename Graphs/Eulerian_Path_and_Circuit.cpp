// Eulerian Path is a path in graph that visits every edge exactly once. 
// Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex.
// The task is to find that there exists the Euler Path or circuit or none
// in given undirected graph.

int Graph::isEulerian()
{
//add code here.
    int even=0,odd=0;
    for(int i=0;i<V;i++){
        if(adj[i].size()%2!=0)
            odd++;
        else
            even++;
    }

    if(even==V)
        return 2; //Eulerian Circuit
    if(odd==2)
        return 1; //Eulerian Path
    return 0;
}
