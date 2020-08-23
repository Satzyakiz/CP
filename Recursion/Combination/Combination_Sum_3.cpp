// Find all possible combinations of k numbers that add up to a number n,
// given that only numbers from 1 to 9 can be used and each combination
// should be a unique set of numbers.
//
// Note:
//
// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:
//
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

void helper(int k, int n, vector<vector<int>> &ans, vector<int> temp){
    if(k < 0) return;
    if(n < 0) return;
    if(k == 0 && n == 0){
        ans.push_back(temp);
        return;
    }
    if(k == 0 || n == 0)
        return;
    int val = temp.size() ? temp.back() + 1 : 1;
    for(int i=val; i<=9; i++){
        temp.push_back(i);
        helper(k-1,n-i,ans,temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;
    helper(k, n, ans, temp);
    return ans;
}
