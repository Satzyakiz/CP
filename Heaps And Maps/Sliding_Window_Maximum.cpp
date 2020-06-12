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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
          deque<int> dq;
          vector<int> ans;
          for(int i=0; i<nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])
              dq.pop_back();
            dq.push_back(i);

            while(!dq.empty() && dq.front() <= i-k)
              dq.pop_front();
            if(i >= k-1){
              ans.emplace_back(nums[dq.front()]);
            }
          }
          return ans;
    }
