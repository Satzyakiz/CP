// Given a complete binary tree, count the number of nodes.
//
// Note:
//
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is
// completely filled, and all nodes in the last level are as far left as
// possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
// Example:
//
// Input:
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
//
// Output: 6


int count;
void inorder(TreeNode *root){
    if(root == NULL)
        return;
    inorder(root->left);
    count++;
    inorder(root->right);
}
int countNodes(TreeNode* root) {
    count = 0;
    inorder(root);
    return count;
}
