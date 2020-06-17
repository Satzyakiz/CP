// Given a square chessboard, the initial position of Knight and position
// of a target. Find out the minimum steps a Knight will take to reach the
// target position.
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 1000
// 1 <= knight_pos(X, Y), targer_pos(X, Y) <= N
//
// Example:
// Input:
// 2
// 6
// 4 5
// 1 1
// 20
// 5 7
// 15 20
//
// Output:
// 3
// 9

int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    // code here
    vector<vector<int>> visited(N+1,vector<int>(N+1));
    queue<pair<int,int>> q;
    int tX = targetPos[0], tY = targetPos[1];
    int x = knightPos[0], y = knightPos[1];
    q.push({x,y});
    int steps = 0;
    while(!q.empty()){
        int k = q.size();
        while(k--){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x == tX && y == tY)
                return steps;
            if(visited[x][y])
                continue;

            visited[x][y] = 1;
            //Top
            if(x-2 >=0 && y-1 >= 0)
                q.push({x-2,y-1});
            if(x-2 >=0 && y+1 <= N)
                q.push({x-2,y+1});

            //Left
            if(x-1 >=0 && y-2 >= 0)
                q.push({x-1,y-2});
            if(x+1 <= N && y-2 >=0)
                q.push({x+1,y-2});

            //Bottom
            if(x+2 <=N && y-1 >= 0)
                q.push({x+2,y-1});
            if(x+2 <=N && y+1 <= N)
                q.push({x+2,y+1});

            //Right
            if(x-1 >=0 && y+2 <= N)
                q.push({x-1,y+2});
            if(x+1 <=N && y+2 <= N)
                q.push({x+1,y+2});
        }
        steps++;
    }
}
