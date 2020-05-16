
struct Node{
  int val;
  struct Node *left,*right;
}
Node * lca(Node *root,int a,int b){
  if(root == NULL) return NULL; //If node not found
  if(root->val == a || root->val == b) return root;

  Node *left = lca(root->left,a,b);
  Node *right = lca(root->right,a,b);

  if(left && right) return root; //Both a and b is present on 2 different
  //sides of root

  return left != NULL ? left : right; //Return the node which have returned
  //some value
  //If one or both of them is not there, returned value would be NULL
}
