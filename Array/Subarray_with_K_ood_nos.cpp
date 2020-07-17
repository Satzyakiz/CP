// Given an array of integers nums and an integer k. A subarray is
// called nice if there are k odd numbers on it.
//
// Return the number of nice sub-arrays.
// Example 1:
//
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:
//
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.
// Example 3:
//
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16

// exactly(K) = atMost(K) - atMost(K-1)

int atMost(vector<int> &nums,int k){
    int ans = 0, i=0;
    for(int j=0; j<nums.size(); j++){
        k -= nums[j]%2;
        while(k < 0){
            k += nums[i]%2;
            i++;
        }
        ans += j-i+1;
    }
    return ans;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(nums,k) - atMost(nums,k-1);
}
