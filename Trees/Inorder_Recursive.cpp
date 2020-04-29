

//TreeNode is of form ->
struct TreeNode{
  int val;
  struct TreeNode *left, *right;
}

void inorder(TreeNode *head,vector<int> &ans){
  if(root == NULL) return;
  inorder(root->left);
  ans.emplace_back(root->val);
  inorder(root->right);
}

//Return a array after inorder traversal
vector<int> inorderTraversal(TreeNode *root){
  vector<int> ans;
  inorder(root,ans);
  return ans; // Inorder traversal is stored in this vector
}
