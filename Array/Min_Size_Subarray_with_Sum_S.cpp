// Given an array of n positive integers and a positive integer s, find the
// minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
// one, return 0 instead.
//
// Example:
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the
// problem constraint.

int minSubArrayLen(int s, vector<int>& A) {
    int i = 0, n = A.size(), res = n + 1;
    for (int j = 0; j < n; ++j) {
        s -= A[j];
        while (s <= 0) {
            res = min(res, j - i + 1);
            s += A[i++];
        }
    }
    return res % (n + 1);
}
//Other Solution
int minSubArrayLen(int s, vector<int> nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1){
        if(nums[0] >= s) return 1;
    }
    int i=0,j=0,sum = nums[i],size=0,maxSize = INT_MAX;
    while(i<n && j<n){
        if(i == j){
            if(nums[i] >= s) return 1;
            else{
                sum = nums[i];
            }
        }
        if(sum >= s){
            maxSize = min(j-i+1,maxSize);
            sum -= nums[i++];
        }
        else{
            j++;
            if(j < n){
                sum += nums[j];
            }
        }
    }
    return maxSize == INT_MAX ? 0: maxSize;
}
