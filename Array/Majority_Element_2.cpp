// Given an integer array of size n, find all elements that appear
// more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
// Input: [3,2,3]
// Output: [3]
// Example 2:
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
vector<int> majorityElement(vector<int>& nums) {

    int count1 = 0, count2 = 0;
    int ele1 = 0, ele2 = 1;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == ele1)
            count1++;
        else if(nums[i] == ele2)
            count2++;
        else if(count1 == 0){
            ele1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0){
            ele2 = nums[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for(int x: nums){
        if(x == ele1)
            count1++;
        if(x == ele2)
            count2++;
    }
    vector<int> ans;
    if(count1 > nums.size()/3)
        ans.emplace_back(ele1);
    if(count2 > nums.size()/3)
        ans.emplace_back(ele2);
    return ans;
}
