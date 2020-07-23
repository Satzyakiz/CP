
// Given an undirected tree with an even number of nodes.
// Consider each connection between a parent and child node to be an edge.
//
// You need to remove maximum number of these edges, such that the
// disconnected subtrees that remain each have an even number of nodes.
//
// Return the maximum number of edges you can remove.
//
// Input 1:
//  A = 6
//  B = [
//        [1, 2]
//        [1, 3]
//        [1, 4]
//        [3, 5]
//        [4, 6]
//      ]
// Input 2:
//  A = 2
//  B = [
//        [1, 2]
//      ]
//
//
// Example Output
// Output 1:
//  2
// Output 2:
//  0
//
// Explanation 1:
//       1
//     / | \
//    2  3  4
//       |   \
//       5    6
// Maximum number of edges we can remove is 2, i.e (1, 3) and (1, 4)
// Explanation 2:
// We can't remove any edges.


vector<vector<int>> adj;
vector<int> visited;
int ans;
int DFS(int index){
    int count = 0;
    visited[index] = 1;
    for(int &c: adj[index]){
        if(visited[c] == 0){
            int subtreeCount = DFS(c);
            if(subtreeCount % 2 == 0)
                ans++;
            else
                count += subtreeCount;
        }
    }
    return count+1;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    adj.clear();
    visited.clear();
    vector<int> temp1(A+1);
    visited = temp1;
    vector<vector<int>> temp2(A+1);
    adj = temp2;
    for(int i=0; i<B.size(); i++){
        int x = B[i][0], y = B[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans = 0;
    DFS(1);
    return ans;
}
