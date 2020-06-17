// Given an array ‘A’ of sorted integers and another non negative integer k,
// find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
int Solution::diffPossible(vector<int> &A, int B) {
    if(A.size() == 1 || A.size() == 0) return 0;
    int l=0, h = 1;
    while(l <= h && h < A.size()){
        if(l == h)
            h++;
        if(A[h] - A[l] == B)
            return 1;
        else if(A[h]-A[l] > B)
            l++;
        else
            h++;
    }
    return 0;
}
