// Given a 2 x N grid of integer, A, choose numbers such that the
// sum of the numbers is maximum and no two chosen numbers are adjacent
// horizontally, vertically or diagonally, and return it.
//
// Note: You can choose more than 2 numbers.

// Input 1:
//     A = [   [1]
//             [2]    ]
//
// Output 1:
//     2
//
// Explanation 1:
//     We will choose 2.
//
// Input 2:
//     A = [   [1, 2, 3, 4]
//             [2, 3, 4, 5]    ]
//
// Output 2:
//     We will choose 3 and 5.

int helper(vector<vector<int>> &A,unordered_map<int,int> &um,int j){
    if(j >= A[0].size())
        return 0;
    if(um.find(j) != um.end())
        return um[j];
    int ans = max(max(A[0][j],A[1][j])+helper(A,um,j+2) , helper(A,um,j+1));
    return um[j] = ans;
}
int Solution::adjacent(vector<vector<int> > &A) {
    unordered_map<int,int> um;
    return helper(A,um,0);
}
