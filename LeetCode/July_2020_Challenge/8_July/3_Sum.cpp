// Given an array nums of n integers, are there elements a, b, c
// in nums such that a + b + c = 0? Find all unique triplets in the
// array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size(),count = 0;
    vector<vector<int>> ans;
    if(n < 3) return ans;
    sort(nums.begin(),nums.end());

    for(int i=0; i<n-2; i++){

        int target = -nums[i];
        int j = i+1, k = n-1;
        while(j<k){
            if(nums[j] + nums[k] > target) k--;
            else if(nums[j] + nums[k] < target) j++;
            else{
                cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                ans.push_back({nums[i],nums[j],nums[k]});
                while(k > j && nums[j]==nums[j+1]) j++;
                j++;
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}
