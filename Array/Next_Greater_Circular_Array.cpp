// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2;
// The number 2 can't find next greater number;
// The second 1's next greater number needs to search circularly,
// which is also 2.

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<2*n; j++){
                int ind = j%n;
                if(i == ind){
                    ans.emplace_back(-1);
                    break;
                }else if(nums[ind] > nums[i]){
                    ans.emplace_back(nums[ind]);
                    break;
                }

            }
        }
        return ans;
    }
