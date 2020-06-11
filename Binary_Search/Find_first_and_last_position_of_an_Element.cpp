// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1,last = -1;
        int low = 0,high=nums.size()-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        low = 0,high=nums.size()-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return {first,last};
    }
