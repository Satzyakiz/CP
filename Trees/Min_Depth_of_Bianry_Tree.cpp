// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path
// from the root node down to the nearest leaf node.

int getMinDepth(TreeNode *root){
  if(root == NULL) return INT_MAX;
  if(root->left == NULL && root->right == NULL) return 1;
  //It means it is a leaf node.
  return min(getMinDepth(root->left),getMinDepth(root->right))+1;
}
