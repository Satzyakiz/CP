// Example 1:
//
// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:
//
// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing array by modify at most one element.

bool checkPossibility(vector<int>& nums) {
    int count = 0, n = nums.size();
    for(int i=1,prev=nums[0]; i<n; i++){
        if(nums[i] < prev && count++ > 0){
            return false;
        }
        if(nums[i] < prev && i-2 >= 0 && nums[i-2] > nums[i])
            continue;
        prev = nums[i];
    }
    return true;
}
