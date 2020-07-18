// Your are given an array of positive integers nums.
//
// Count and print the number of (contiguous) subarrays where the product
// of all the elements in the subarray is less than k.
//
// Example 1:
// Input: nums = [10, 5, 2, 6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not
// strictly less than k.


int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int p = 1;
    int i=0, ans = 0;
    if(k == 0)
        return 0;
    for(int j=0; j<nums.size(); j++){
        p *= nums[j];
        while(p >= k && i<=j){
            p /= nums[i++];
        }
        ans += j-i+1;
    }
     return ans;
}
