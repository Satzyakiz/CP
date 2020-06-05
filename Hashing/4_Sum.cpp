// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

//Source: Interviewbit (Hard Problem)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> ansSet;
        unordered_map<int,vector<pair<int,int>>> um;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i]+nums[j];
                int diff = target - sum;
                if(um.find(diff) != um.end()){
                    for(auto p: um[diff]){
                        // cout<<p.first<<" "<<p.second<<endl;
                        if(i != p.first && i != p.second && j != p.first && j != p.second){
                            vector<int> temp;
                            temp.emplace_back(nums[i]);
                            temp.emplace_back(nums[j]);
                            temp.emplace_back(nums[p.first]);
                            temp.emplace_back(nums[p.second]);
                            sort(temp.begin(),temp.end());
                            ansSet.insert(temp);
                        }

                    }
                }
                um[sum].push_back({i,j});
            }
        }
        for(auto i=ansSet.begin(); i!=ansSet.end(); i++){
            ans.emplace_back(*i);
        }
        return ans;
    }
