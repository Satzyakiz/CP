// Given a 2D integer array A of size  N * N  representing a triangle of numbers.
//
// Find the maximum path sum from top to bottom. Each step you may move
// to adjacent numbers on the row below.
//
// NOTE:
//
// Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
// Row i contains i integer and n-i zeroes for all i in [1,n] where
// zeroes represents empty cells.
// Explanation 1:
//
//  Given triangle looks like:  3
//                              7 4
//                              2 4 6
//                              8 5 9 3
//         So max path is (3 + 7 + 4 + 9) = 23
// Explanation 1:
//
//  Given triangle looks like:  8
//                              4 4
//                              2 2 6
//                              1 1 1 1
//         So max path is (8 + 4 + 6 + 1) = 19




int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> maxArr(A.back());
    for(int len = n-2; len >= 0; len--){
        for(int i=0; i <= len; i++)
            maxArr[i] = max(maxArr[i],maxArr[i+1]) + A[len][i];
    }

    return maxArr[0];
}
