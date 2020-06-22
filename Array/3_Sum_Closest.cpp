// Given an array nums of n integers and an integer target,
// find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each input
// would have exactly one solution.
//
//
//
// Example 1:
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int k = nums.size()-1;
                while(j < k){
                    int temp = nums[i]+nums[j]+nums[k];
                    if(abs(temp - target) < abs(ans - target))
                        ans = temp;
                    if(temp < target)
                        j++;
                    else
                        k--;
                }
            }
        }
        return ans;
    }
