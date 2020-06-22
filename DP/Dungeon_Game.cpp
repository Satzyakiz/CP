// The demons had captured the princess (P) and imprisoned her in
// the bottom-right corner of a dungeon. The dungeon consists of M x N rooms
// laid out in a 2D grid. Our valiant knight (K) was initially positioned
// in the top-left room and must fight his way through the dungeon to
// rescue the princess.
//
// The knight has an initial health point represented by a positive integer.
// If at any point his health point drops to 0 or below, he dies immediately.
//
// Some of the rooms are guarded by demons, so the knight loses health
// (negative integers) upon entering these rooms; other rooms are either
// empty (0's) or contain magic orbs that increase the knight's health
// (positive integers).
//
// In order to reach the princess as quickly as possible, the knight
// decides to move only rightward or downward in each step.

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();

    vector<vector<int> > dp(M, vector<int>(N, INT_MAX));
    dp[M-1][N-1] = dungeon[M-1][N-1];

    for(int i=M-1; i>=0; i--){
        for(int j=N-1; j>=0; j--){
            if(i == M-1 && j == N-1)
                dp[i][j] = min(0,dungeon[i][j]);
            else if(i == M-1)
                dp[i][j] = min(0,dp[i][j+1] + dungeon[i][j]);
            else if(j == N-1)
                dp[i][j] = min(0,dp[i+1][j] + dungeon[i][j]);
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]) + dungeon[i][j];
                dp[i][j] = min(0,dp[i][j]);
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return abs(dp[0][0])+1;
}
