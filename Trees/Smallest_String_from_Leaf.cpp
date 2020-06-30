// Given the root of a binary tree, each node has a value from 0 to 25
// representing the letters 'a' to 'z': a value of 0 represents 'a', a value
// of 1 represents 'b', and so on.
//
// Find the lexicographically smallest string that starts at a leaf of this
// tree and ends at the root.
//
// (As a reminder, any shorter prefix of a string is lexicographically
//     smaller: for example, "ab" is lexicographically smaller than "aba".
//      A leaf of a node is a node that has no children.)
//
//
//
// Example 1:
//
// Input: [0,1,2,3,4,3,4]
// Output: "dba"
// Example 2:
//
// Input: [25,1,3,1,3,0,2]
// Output: "adz"
// Example 3:
//
// Input: [2,2,1,null,1,0,null,0]
// Output: "abc"

void dfs(TreeNode *root,string s,vector<string> &ans){
    if(root == NULL) return;
    if(!root->left && !root->right){
        s += root->val+'a';
        reverse(s.begin(),s.end());
        ans.emplace_back(s);
        return;
    }
    s += root->val+'a';
    dfs(root->left,s,ans);
    dfs(root->right,s,ans);
}
string smallestFromLeaf(TreeNode* root) {
    if(root == NULL){
        return "";
    }
    vector<string> ans;
    string s;
    dfs(root,s,ans);
    sort(ans.begin(),ans.end());
    return ans[0];
}
