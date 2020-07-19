// Suppose an array sorted in ascending order is rotated at some pivot
// unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true,
// otherwise return false.
//
// Example 1:
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

//Contains Duplicates

bool search(vector<int>& nums, int target) {
    int n = nums.size(), start = 0, end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target)
            return true;

        if(nums[mid] < nums[end]){
            if(nums[mid] < target && target <= nums[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }else if(nums[mid] > nums[end]){
            if(nums[start] <= target && target < nums[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }else{
            end--;
        }
    }
    return false;
}
