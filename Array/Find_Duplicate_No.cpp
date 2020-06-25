// Given an array nums containing n + 1 integers where each integer is 
// between 1 and n (inclusive), prove that at least one duplicate number
// must exist. Assume that there is only one duplicate number, find
// the duplicate one.
//
// Example 1:
//
// Input: [1,3,4,2,2]
// Output: 2
// Example 2:
//
// Input: [3,1,3,4,2]
// Output: 3


int findDuplicate(vector<int>& nums) {
    int n = nums.size(),ans=0;
    for(int i=0; i<n; i++){
        while(nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            swap(nums[i],nums[nums[i]-1]);
    }
    for(int i=0; i<n; i++)
        if(nums[i] != i+1)
            return nums[i];
    return 0;
}
