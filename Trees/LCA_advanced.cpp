// You are given 2 values. Find the lowest common ancestor
// of the two nodes represented by val1 and val2
// No guarantee that val1 and val2 exist in the tree.
// If one value doesn’t exist in the tree then return -1.
// There are no duplicate values.
// You can use extra memory, helper functions,
// and can modify the node struct but, you can’t add a parent pointer.

bool search(TreeNode *A,int x){
  if(A == NULL) return false;
  if(A->val == x) return true;
  return search(A->left,x) || search(A->right,x);
}

int lca(TreeNode *A,int B,int C){
  if(A == NULL) return 0;
  if(!(search(A,B) && search(A,C)))
    return -1;
  if(search(A->left,B) && search(A->left,C))
  //If both B and C are present on left sub-tree
    return lca(A->left,B,C);
  else if(search(A->right,B) && search(A->right,C))
  //If both B and C are present on right sub-tree
    return lca(A->right,B,C);
  else
    return A->val;
}
