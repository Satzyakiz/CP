// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

//k : window size
vector<int> slidingWindowMaximum(vector<int> nums,int k){
  deque<int> dq;
  vector<int> ans;
  for(int i=0; i<nums.size(); i++){
    //If any smaller element than the current element is present in the deque
    //we remove it
    while(!dq.empty() && nums[dq.back()] <= nums[i])
      dq.pop_back();
    //Every element would be part of the deque
    dq.push_back(i);

    //If the largest element is not part of the window, it is removed
    while(!dq.empty() && dq.front() <= i-k)
      dq.pop_front();
    if(i >= k-1){
      ans.emplace_back(nums[dq.front()]);
    }
  }
  return ans;
}
