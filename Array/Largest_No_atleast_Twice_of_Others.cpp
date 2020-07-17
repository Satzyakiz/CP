
// Example 1:
//
// Input: nums = [3, 6, 1, 0]
// Output: 1
// Explanation: 6 is the largest integer, and for every other
// number in the array x,6 is more than twice as big as x.  The index of
// value 6 is 1, so we return 1.
//
//
// Example 2:
//
// Input: nums = [1, 2, 3, 4]
// Output: -1
// Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.


int dominantIndex(vector<int>& nums) {
    if(nums.size() == 1)
        return 0;
    int max1 = nums[0], max2 = nums[1], index = 0;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] > max1){
            max2 = max1;
            max1 = nums[i];
            index = i;
        }else if(nums[i] > max2){
            max2 = nums[i];
        }
    }
    return max1 >= 2 * max2 ? index : -1;
}
