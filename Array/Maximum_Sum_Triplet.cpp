// Given an array A containing N integers.
//
// You need to find the maximum sum of triplet ( Ai + Aj + Ak )
// such that 0 <= i < j < k < N and Ai < Aj < Ak.
//
// If no such triplet exist return 0.
//
//
//
// Problem Constraints
// 3 <= N <= 105.
//
// 1 <= A[i] <= 108.
//
//
//
// Input Format
// First argument is an integer array A.
//
//
//
// Output Format
// Return a single integer denoting the maximum sum of triplet as
// described in the question.
//
//
//
// Example Input
// Input 1:
//
//  A = [2, 5, 3, 1, 4, 9]
// Input 2:
//
//  A = [1, 2, 3]
//
//
// Example Output
// Output 1:
//
//  16
// Output 2:
//
//  6
//
//
// Example Explanation
// Explanation 1:
//
//  All possible triplets are:-
//     2 3 4 => sum = 9
//     2 5 9 => sum = 16
//     2 3 9 => sum = 14
//     3 4 9 => sum = 16
//     1 4 9 => sum = 14
//   Maximum sum = 16
// Explanation 2:
//
//  All possible triplets are:-
//     1 2 3 => sum = 6
//  Maximum sum = 6

int Solution::solve(vector<int> &A) {
    int n = A.size(), num, sum, maxSum = INT_MIN;
    vector<int> rightMax(n), leftMax(n);
    rightMax[n - 1] = A[n - 1];
    leftMax[0] = A[0];
    set<int> left;
    left.insert(A[0]);

    for(int i = n - 2; i >= 0; --i) {
        if(rightMax[i + 1] > A[i]) {
            rightMax[i] = rightMax[i + 1];
        } else {
            rightMax[i] = A[i];
        }
    }
    for(int i = 1; i < n; ++i) {
        left.insert(A[i]);

        auto it = left.find(A[i]);

        if(it != left.begin()) {
            --it;
            leftMax[i] = *it;
        } else {
            leftMax[i] = A[i];
        }
    }

    for(int i = 0; i < n; ++i) {
        if(A[i] != rightMax[i] && A[i] != leftMax[i]) {
            sum = A[i] + rightMax[i] + leftMax[i];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
