

int getMaxDepth(TreeNode *root){
  if(root == NULL) return 0;
  return max(1+getMaxDepth(root->left),1+getMaxDepth(root->right));
}
