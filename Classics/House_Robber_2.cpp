// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed. All houses at this
// place are arranged in a circle. That means the first house is the
// neighbor of the last one. Meanwhile, adjacent houses have security
// system connected and it will automatically contact the police if two
// adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of
// money of each house, determine the maximum amount of money you can
// rob tonight without alerting the police.
//
// Example 1:
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3
// (money = 2), because they are adjacent houses.
// Example 2:
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

//Same like house robber problem.
// Find results include first and excluding last and vice versa
//Return the greatest among those two
int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int includeIt = nums[0], excludeIt = 0;
        for(int i=1; i<nums.size()-1; i++){
            int temp = includeIt;
            includeIt = max(excludeIt + nums[i],includeIt);
            excludeIt = max(temp,excludeIt);
        }
        int maxIncludeFirst = includeIt > excludeIt ? includeIt : excludeIt;
        includeIt = nums[1], excludeIt = 0;
        for(int i=2; i<nums.size(); i++){
            int temp = includeIt;
            includeIt = max(excludeIt + nums[i],includeIt);
            excludeIt = max(temp,excludeIt);
        }
        int maxIncludeLast = includeIt > excludeIt ? includeIt : excludeIt;

        return maxIncludeFirst > maxIncludeLast ? maxIncludeFirst : maxIncludeLast;
    }
