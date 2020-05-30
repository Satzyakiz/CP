// There are a total of numCourses courses you have to take,
// labeled from 0 to numCourses-1.
//
// Some courses may have prerequisites, for example to take course 0
// you have to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs,
// is it possible for you to finish all courses?
//
//
//
// Example 1:
//
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0.
//              So it is possible.
// Example 2:
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0,
//              and to take course 0 you should
//              also have finished course 1. So it is impossible.

bool cycle(vector<vector<int>> &adjMat,int index,vector<bool> &tempVisited,vector<bool> &visited){
    visited[index] = true;
    tempVisited[index] = true;
    for(int j=0; j<adjMat[index].size(); j++){
        int t = adjMat[index][j];

        if(!visited[t] && cycle(adjMat,t,tempVisited,visited))
            return true;
        else if(tempVisited[t])
            return true;

    }
    tempVisited[index] = false;
    return false;
}
bool isCycle(vector<vector<int>> &adjMat){
    int n = adjMat.size();
    vector<bool> visited(n,false);
    vector<bool> tempVisited(n,false);
    for(int i=0; i<n; i++){
        if(!visited[i] && cycle(adjMat,i,tempVisited,visited))
            return true;
    }
    return false;
}
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjMat(n);
        for(int i=0; i<prerequisites.size(); i++){
            adjMat[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        }
        for(int i=0; i<n; i++){
            if(isCycle(adjMat))
                return false;
        }
        return true;
    }
};
