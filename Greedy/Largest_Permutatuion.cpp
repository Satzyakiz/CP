// Given an integer array A of size N consisting of unique integers from 1 to N.
// You can swap any two integers atmost B times.
//
// Return the largest lexicographical value array that can be created by
// executing atmost B swaps.
//
// Input 1:
//
//  A = [1, 2, 3, 4]
//  B = 1
// Input 2:
//
//  A = [3, 2, 1]
//  B = 2
//
//
// Example Output
// Output 1:
//
//  [4, 2, 3, 1]
// Output 2:
//
//  [3, 2, 1]

vector<int> Solution::solve(vector<int> &A, int B) {
    if(B == 0)
        return A;
    int n = A.size();
    if(n < 2)
        return A;
    vector<int> pos(n+1);
    for(int i=0; i<n; i++){
        pos[A[i]] = i;
    }

    for(int i=0; i<n && B>0; i++){
        if(A[i] != (n-i)){
            pos[A[i]] = pos[n-i];
            swap(A[i],A[pos[n-i]]);
            B--;
        }
    }

    return A;
}
