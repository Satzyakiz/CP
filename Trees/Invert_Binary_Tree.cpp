
TreeNode *invertTree(TreeNode *A){
  if(A == NULL) return A;
  TreeNode *temp = A->right;
  A->right = A->left;
  A->left = temp;
  A->left = invertTree(A->left);
  A->right = invertTree(A->right);
  return A;
}
