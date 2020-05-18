
int getHeight(TreeNode *root){
  if(root == NULL) return 0;
  return max(1+getHeight(root->left),1+getHeight(root->right));
}

bool isBalanced(TreeNode *root){
  if(root == NULL) return true;
  int left = getHeight(root->left);
  int right = getHeight(root->right);
  if(abs(left - right) < 2)
    return isBalanced(root->left) && isBalanced(root->right);
  else
    return false;
}
