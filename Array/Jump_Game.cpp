

// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what.
// Its maximum jump length is 0, which makes it impossible



bool canJump(vector<int>& nums) {
        int n = nums.size(),end = n-1;
        for(int i=n-1; i>=0; i--){
            if(i + nums[i] >= end)
                end = i;
                //If jumps are possible to the end from location i,
                //we need to see whether we can reach i
        }
        return end == 0;
        //If end can reach the start,
        // it means jumps is possible to the end
    }
