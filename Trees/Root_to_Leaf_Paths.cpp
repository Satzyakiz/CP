
// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3



void dfs(TreeNode *root,string s,vector<string> &ans){
    if(root == NULL) return;
    if(!root->left && !root->right){
        s += to_string(root->val);
        ans.emplace_back(s);
        return;
    }
    s += to_string(root->val) + "->";
    dfs(root->left,s,ans);
    dfs(root->right,s,ans);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string s;
    dfs(root,s, ans);
    return ans;
}
