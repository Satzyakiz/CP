// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

//DP
int getMaxProduct(vector<int> nums){
  int n = nums.size(),temp;
  vector<int> maxArr(n),minArr(n);
  maxArr[0] = minArr[0] = nums[0];
  for(int i=1; i<n; i++){
    temp = max(maxArr[i-1]*nums[i],minArr[i-1]*nums[i]);
    maxArr[i] = max(nums[i],temp);
    temp = min(maxArr[i-1]*nums[i],minArr[i-1]*nums[i]);
    minArr[i] = min(nums[i],temp);
  }
  return *max_element(maxArr.begin(),maxArr.end());
}
