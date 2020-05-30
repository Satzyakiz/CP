//
// Given a set of N people (numbered 1, 2, ..., N), we would
// like to split everyone into two groups of any size.
//
// Each person may dislike some other people, and they should not
// go into the same group.
//
// Formally, if dislikes[i] = [a, b], it means it is not allowed to
// put the people numbered a and b into the same group.
//
// Return true if and only if it is possible to split everyone into
// two groups in this way.
//
//
//
// Example 1:
//
// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:
//
// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:
//
// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false


bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjMat(N+1);
        for(auto d: dislikes){
            adjMat[d[0]].emplace_back(d[1]);
            adjMat[d[1]].emplace_back(d[0]);
        }

        vector<int> col(N+1,0);
        vector<bool> visited(N+1,false);
        queue<int> q;
        for(int i=1; i<N+1; i++){
            if(visited[i]){
                continue;
            }
            col[i] = 1;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(visited[u]) continue;
                visited[u] = true;
                for(int j=0; j<adjMat[u].size(); j++){
                    int v = adjMat[u][j];
                    if(col[u] == col[v]) return false;
                    if(col[u] == 1) col[v] = 2;
                    else col[v] = 1;
                    q.push(v);
                }
            }
        }

        return true;
    }
