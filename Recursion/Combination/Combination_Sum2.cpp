//
// Given a collection of candidate numbers (candidates) and a
// target number (target), find all unique combinations in candidates
// where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

vector<vector<int>> ans;
    void combinations(vector<int> &candidates,int target,int start,vector<int> tempAns){
        if(target < 0) return;
        if(target == 0 && find(ans.begin(),ans.end(),tempAns) == ans.end()){
            ans.emplace_back(tempAns);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            tempAns.emplace_back(candidates[i]);
            combinations(candidates,target-candidates[i],i+1,tempAns);
            tempAns.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tempAns;
        sort(candidates.begin(),candidates.end());
        combinations(candidates,target,0,tempAns);
        return ans;
    }

//Interviewbit version
void combinations(vector<int> &A,int B,int start,vector<int> &tempAns,vector<vector<int>> &ans){
    if(B < 0) return;
    if(B == 0 && find(ans.begin(),ans.end(),tempAns) == ans.end()){
        ans.emplace_back(tempAns);
        return;
    }
    for(int i=start; i<A.size(); i++){
        tempAns.emplace_back(A[i]);
        combinations(A,B-A[i],i+1,tempAns,ans);
        tempAns.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    vector<int> tempAns;
    combinations(A,B,0,tempAns,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
