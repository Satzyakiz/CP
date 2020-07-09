// Consider a rat placed at (0, 0) in a square matrix of order N*N.
// It has to reach the destination at (n-1, n-1). Find all possible
// paths that the rat can take to reach from source to destination.
// The directions in which the rat can move are 'U'(up), 'D'(down),
// 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents
// that it is blocked and cannot be crossed while value 1 at a cell in
// the matrix represents that it can be travelled through.

// Input:
// 3
// 4
// 1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
// 4
// 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
// 2
// 1 0 1 0
//
// Output:
// DRDDRR
// DDRDRR DRDDRR
// -1

void DFS(int m[MAX][MAX],int n,int i,int j,string s, vector<string> &ans){
    if(i == n-1 && j == n-1 && m[i][j] != 0){
        ans.emplace_back(s);
        return;
    }
    if(i<0 || j<0 || i>=n || j>=n || m[i][j] == 0 || m[i][j] == -1){
        return;
    }
    m[i][j] = -1;
    DFS(m,n,i-1,j,s+'U',ans);
    DFS(m,n,i+1,j,s+'D',ans);
    DFS(m,n,i,j-1,s+'L',ans);
    DFS(m,n,i,j+1,s+'R',ans);
    m[i][j] = 1;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> ans;
    DFS(m,n,0,0,"",ans);
    if(ans.size() == 0){
        ans.emplace_back("-1");
        return ans;
    }
    sort(ans.begin(),ans.end());
    return ans;
}
