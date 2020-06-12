// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
// some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]


vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int x: nums){
            x = abs(x); //To get +ve values even for -ve nos
            if(nums[x-1] < 0)
                ans.emplace_back(x);
            else
                nums[x-1] = -nums[x-1];
        }

        return ans;
    }
