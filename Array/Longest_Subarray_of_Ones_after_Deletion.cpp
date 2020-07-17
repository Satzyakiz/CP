// Given a binary array nums, you should delete one element from it.
//
// Return the size of the longest non-empty subarray containing
// only 1's in the resulting array.
//
// Return 0 if there is no such subarray.
//
// Example 1:
//
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1]
// contains 3 numbers with value of 1's.
// Example 2:
//
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
// longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:
//
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
// Example 4:
//
// Input: nums = [1,1,0,0,1,1,1,0,1]
// Output: 4

//Sliding Window
int longestSubarray(vector<int>& nums) {
        int l=0, r=0, n=nums.size(), zeroes=0, ones=0, res=0;
        while(r<n){
            while(zeroes<2 and r<n)
                nums[r++]==1 ? ones++ : zeroes++;
            res=max(res,ones);
            while(zeroes==2)
                nums[l++]==1 ? ones-- : zeroes--;
        }
        return zeroes ? res : res-1;
}

//Extra Space
bool allOnes(vector<int> &nums){
    for(int &x: nums)
        if(x != 1)
            return false;
    return true;
}
int longestSubarray(vector<int>& nums) {
    if(allOnes(nums))
        return nums.size()-1;
    vector<int> arr;
    int count = 0;
    for(int &x : nums){
        if(x == 0){
            if(count != 0){
                arr.emplace_back(count);
                count = 0;
            }
            arr.emplace_back(x);
        }
        else
            count++;
    }
    if(count)
        arr.emplace_back(count);
    arr.insert(arr.begin(),0);
    arr.emplace_back(0);
    int maxVal = 0;
    for(int i=1; i<arr.size()-1;i++){
            maxVal = max(arr[i-1] + arr[i+1] , maxVal);
    }
    return maxVal;
}
