// A binary tree is univalued if every node in the tree has the same value.
//
// Return true if and only if the given tree is univalued.
//
// Input: [2,2,2,5,2]
// Output: false
// Input: [1,1,1,1,1,null,1]
// Output: true

bool isUnivalTree(TreeNode* root) {
    if(!root || !root->left && !root->right)
        return true;
    if(root->left && root->right){
        if( root->left->val == root->val && root->val == root->right->val){
            return isUnivalTree(root->left) && isUnivalTree(root->right);
        }else{
            return false;
        }
    }else if(root->left){
        if(root->left->val == root->val)
            return isUnivalTree(root->left);
        else
            return false;
    }else if(root->right){
        if(root->right->val == root->val)
            return isUnivalTree(root->right);
        else
            return false;
    }else
        return false;

}
