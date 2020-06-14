
// Input:
//
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:
//
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
