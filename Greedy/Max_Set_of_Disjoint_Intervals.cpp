// Given a set of N intervals denoted by 2D array A of size N x 2, the task is 
// to find the length of maximal set of mutually disjoint intervals.
//
// Two intervals [x, y] & [p, q] are said to be disjoint if they do not
// have any point in common.
//
// Return a integer denoting the length of maximal set of mutually
// disjoint intervals.
// Input 1:
//
//  A = [
//        [1, 4]
//        [2, 3]
//        [4, 6]
//        [8, 9]
//      ]
// Input 2:
//
//  A = [
//        [1, 9]
//        [2, 3]
//        [5, 7]
//      ]
//
//
// Example Output
// Output 1:
//
//  3
// Output 2:
//
//  2
//
//
// Example Explanation
// Explanation 1:
//
//  Intervals: [ [1, 4], [2, 3], [4, 6], [8, 9] ]
//  Intervals [2, 3] and [1, 4] overlap.
//  We must include [2, 3] because if [1, 4] is included then
//  we cannot include [4, 6].
//  We can include at max three disjoint intervals: [[2, 3], [4, 6], [8, 9]]
// Explanation 2:
//
//  Intervals: [ [1, 9], [2, 3], [5, 7] ]
//  We can include at max two disjoint intervals: [[2, 3], [5, 7]]


bool compare(const vector<int> A,const vector<int> B){
    return A[1] < B[1];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),compare);
    int ans = 1, j = 0;
    for(int i=1; i<A.size(); i++){
        if(A[j][1] < A[i][0]){
            ans++;
            j = i;
        }
    }
    return ans;
}
