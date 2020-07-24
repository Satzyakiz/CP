// Given an integer array A of size N containing 0's and 1's only.
//
// You need to find the length of the longest subarray having count of 1’s
// one more than count of 0’s.
//
// Input 1:
//
//  A = [0, 1, 1, 0, 0, 1]
// Input 2:
//
//  A = [1, 0, 0, 1, 0]
//
// Output 1:
//
//  5
// Output 2:
//
//  1

 int Solution::solve(vector<int> &A) {
    for(int i=0; i<A.size(); i++)
        if(A[i] == 0)
            A[i] = -1;

    unordered_map<int,int> um;
    int sum = 0,ans = 0;
    for(int i=0; i<A.size(); i++){
        sum += A[i];
        if(sum == 1){
            ans = i+1;
        }
        if(um.count(sum-1)){
            ans = max(ans, i - um[sum-1]);
        }
        if(um.count(sum) == 0)
            um[sum] = i;
    }
    return ans;
}
