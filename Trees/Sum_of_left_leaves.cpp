// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15
// respectively. Return 24.

int sum;
bool isLeave(TreeNode *node){
    if(node == NULL)
        return false;
    if(!node->left && !node->right)
        return true;
    return false;
}
void getSum(TreeNode *root){
    if(root == NULL)
        return;
    if(isLeave(root->left)){
        sum += root->left->val;
    }
    getSum(root->left);
    getSum(root->right);

}
int sumOfLeftLeaves(TreeNode* root) {
    sum = 0;
    getSum(root);
    return sum;
}
