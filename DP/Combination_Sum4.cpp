// Given an integer array with all positive numbers and no duplicates,
// find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.


unordered_map<int,int> um;
int helper(vector<int>& nums, int target){
	if(nums.size() == 0 || target < 0)
		return 0;
	if(target == 0)
		return 1;
	if(um.find(target) != um.end())
		return um[target];
	int ans = 0;
	for(int i=0; i<nums.size(); i++)
		ans += helper(nums,target-nums[i]);
	return um[target] = ans;
}
int combinationSum4(vector<int>& nums, int target) {
	um.clear();
	return helper(nums,target);
}
