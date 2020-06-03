// Given a binary tree and a sum, find all root-to-leaf paths
// where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

vector<vector<int>> ans;
    void solve(TreeNode *root,int sum,vector<int> tempPath){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                tempPath.emplace_back(root->val);
                ans.emplace_back(tempPath);
                return;
            }
        }
        tempPath.emplace_back(root->val);
        solve(root->left,sum-root->val,tempPath);
        solve(root->right,sum-root->val,tempPath);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tempPath;
        solve(root,sum,tempPath);

        return ans;
    }
