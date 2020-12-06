// We are given the head node root of a binary tree, where additionally
// every node's value is either a 0 or a 1.
//
// Return the same tree where every subtree (of the given tree)
// not containing a 1 has been removed.
//
// (Recall that the subtree of a node X is X, plus every node that
//     is a descendant of X.)
//
// Example 1:
// Input: [1,null,0,0,1]
// Output: [1,null,0,null,1]
// Example 2:
// Input: [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
// Example 3:
// Input: [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]

    bool hasOne(TreeNode *root){
        if(!root) return false;
        if(root->val == 1) return true;
        return hasOne(root->left) || hasOne(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)  return NULL;
        bool left = hasOne(root->left), right = hasOne(root->right);
        if(root->val == 0 && !left && !right)
            return NULL;
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        pruneTree(root->left);
        pruneTree(root->right);
        return root;
    }

//Alternate
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return NULL;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && root->val == 0) return NULL;
    return root;
}
