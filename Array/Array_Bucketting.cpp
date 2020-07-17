// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation:
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1).
// For nums[3]=2 there exist one smaller number than it (1).
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).


vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> bucket(101), ans(nums.size());
    for(int &x: nums)
        bucket[x]++;
    for(int i=1; i<101; i++){
        bucket[i] += bucket[i-1];
    }
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0)
            ans[i] = 0;
        else
            ans[i] = bucket[nums[i]-1];
    }
    return ans;
}
