
// In an array A of 0s and 1s, how many non-empty subarrays have sum S?

// Example 1:
//
// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation:
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]

int atMost(vector<int> &A,int s){
    if(s < 0)
        return 0;
    int ans = 0,i=0;
    for(int j=0; j<A.size(); j++){
        s -= A[j];
        while(s < 0){
            s += A[i++];
        }
        ans += j-i+1;
    }
    return ans;
}
int numSubarraysWithSum(vector<int>& A, int s) {
    return atMost(A,s) - atMost(A,s-1);
}
