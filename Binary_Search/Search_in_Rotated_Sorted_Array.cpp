// Suppose an array sorted in ascending order is rotated at
// some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array
// return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;

            bool c1 = nums[mid] >= nums[0];
            bool c2 = target >= nums[0];

            if(c1 == c2){
// If both the conditions satisfy, then normal binary search 
                if(nums[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else{
                if(c1){
// If target is smaller than the start and mid and start is smaller than mid
                    start = mid + 1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
