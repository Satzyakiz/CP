// Given a collection of integers that might contain duplicates, nums,
// return all possible subsets (the power set).
//
// i/p:
// [4,4,4,1,4]
// o/p:
// [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]

vector<vector<int>> ans;
    void backtrack(vector<int>& nums,vector<int> tempAns,int s){
        if(s == nums.size()){
            ans.emplace_back(tempAns);
            return;
        }
        backtrack(nums,tempAns,s+1);
        tempAns.emplace_back(nums[s]);
        backtrack(nums,tempAns,s+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tempAns;
        backtrack(nums,tempAns,0);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
