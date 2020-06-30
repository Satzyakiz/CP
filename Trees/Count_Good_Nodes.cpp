// Given a binary tree root, a node X in the tree is named good if in the path
// from root to X there are no nodes with a value greater than X.
//
// Return the number of good nodes in the binary tree.
//
// Input: root = [3,1,4,3,null,1,5]
// Output: 4
// Explanation: Nodes in blue are good.
// Root Node (3) is always a good node.
// Node 4 -> (3,4) is the maximum value in the path starting from the root.
// Node 5 -> (3,4,5) is the maximum value in the path
// Node 3 -> (3,1,3) is the maximum value in the path.
// Input: root = [3,3,null,4,2]
// Output: 3
// Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

int dfs(TreeNode *root,int greatest){
    if(root == NULL) return 0;
    bool isGood = root->val >= greatest;
    greatest = max(root->val,greatest);
    return dfs(root->left,greatest) + dfs(root->right,greatest) + (isGood ? 1: 0);
}
int goodNodes(TreeNode* root) {
    if(root == NULL) return 0;
    return dfs(root,root->val);
}
