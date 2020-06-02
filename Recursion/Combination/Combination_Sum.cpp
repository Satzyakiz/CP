
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]



vector<vector<int>> ans;
    void solve(vector<int> &candidates,int currTarget,vector<int> tempAns,int start){
        if(currTarget < 0)
            return;
        if(currTarget == 0){
            ans.emplace_back(tempAns);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            tempAns.emplace_back(candidates[i]);
            solve(candidates,currTarget-candidates[i],tempAns,i);
            tempAns.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tempAns;
        solve(candidates,target,tempAns,0);
        return ans;
    }

//Interviewbit version
void combinations(vector<int> &A,int B,vector<int> tempAns,int start,vector<vector<int>> &ans){
    if(B < 0) return;
    //find used to check that similar vector is not present
    //in ans already
    if(B == 0 && find(ans.begin(),ans.end(),tempAns)==ans.end()){
        ans.emplace_back(tempAns);
        return;
    }
    for(int i=start; i<A.size(); i++){
        tempAns.emplace_back(A[i]);
        combinations(A,B-A[i],tempAns,i,ans);
        tempAns.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    vector<int> tempAns;
    sort(A.begin(),A.end());
    combinations(A,B,tempAns,0,ans);
    return ans;
}
