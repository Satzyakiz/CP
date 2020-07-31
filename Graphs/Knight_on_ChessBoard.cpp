// Given any source point, (C, D) and destination point, (E, F)
// on a chess board, we need to find whether Knight can move to the
// destination or not.
//
// The above figure details the movements for a knight ( 8 possibilities ).
//
// If yes, then what would be the minimum number of steps for the knight
// to move to the said point.
// If knight can not move from the source point to the destination point,
// then return -1.

// Input 1:
//     A = 8
//     B = 8
//     C = 1
//     D = 1
//     E = 8
//     F = 8
//
// Output 1:
//     6

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> mat(A,vector<int>(B));
    C -= 1, D -= 1, E -= 1, F -= 1;
    queue<pair<int,int>> q;
    q.push({C,D});
    int count = 0;
    map<pair<int,int>,bool> m;
    while(!q.empty()){
        int k = q.size();
        while(k--){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x < 0 || y < 0 || x >= A || y >= B || m.count({x,y}))
                continue;

            if(x == E && y == F)
                return count;
            m[{x,y}] = true;
            q.push({x-1,y-2});
            q.push({x-1,y+2});
            q.push({x+1,y-2});
            q.push({x+1,y+2});
            q.push({x-2,y-1});
            q.push({x-2,y+1});
            q.push({x+2,y-1});
            q.push({x+2,y+1});
        }
        count++;
    }

    return -1;
}
