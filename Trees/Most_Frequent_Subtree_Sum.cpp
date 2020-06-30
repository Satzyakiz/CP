
// Input:
//
//   5
//  /  \
// 2   -3
// return [2, -3, 4], since all the values happen only once, return all
// of them in any order.
// Examples 2
// Input:
//
//   5
//  /  \
// 2   -5
// return [2], since 2 happens twice, however -5 only occur once.

int dfs(TreeNode *root,unordered_map<int,int> &um){
    if(root == NULL) return 0;
    int sum = root->val;
    sum += dfs(root->left,um);
    sum += dfs(root->right,um);
    um[sum]++;
    return sum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int,int> um;
    dfs(root,um);
    int maxVal = INT_MIN;
    for(auto itr=um.begin(); itr!=um.end(); itr++){
        maxVal = max(maxVal,itr->second);
    }
    vector<int> ans;
    if(maxVal == INT_MIN)
        return ans;
    for(auto itr=um.begin(); itr!=um.end(); itr++){
        if(itr->second == maxVal)
            ans.emplace_back(itr->first);
    }
    return ans;
}
