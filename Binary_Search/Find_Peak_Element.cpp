
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should
// return the index number 2.
// Example 2:
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1
// where the peak element is 2,  or index number 5 where the peak element is 6.

int findPeakElement(vector<int>& nums) {
        int n=nums.size(),low = 0,high = n-1;
        if(n == 1) return 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n; //To avoid -ve index cases
            if(nums[mid] >= nums[next] && nums[mid] >= nums[prev])
                return mid;
            else if(nums[mid] < nums[next])
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
