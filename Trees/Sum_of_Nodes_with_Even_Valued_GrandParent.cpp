// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18

void helper(TreeNode *root,int &val){
    if(root == NULL)
        return;
    if(root->val % 2 == 0){
        if(root->left && root->left->left){
            val += root->left->left->val;
        }
        if(root->left && root->left->right){
            val += root->left->right->val;
        }
        if(root->right && root->right->left){
            val += root->right->left->val;
        }
        if(root->right && root->right->right){
            val += root->right->right->val;
        }
    }
    helper(root->left,val);
    helper(root->right,val);
}
int sumEvenGrandparent(TreeNode* root) {
    if(root == NULL)
        return 0;
    int val = 0;
    helper(root,val);
    return val;
}
