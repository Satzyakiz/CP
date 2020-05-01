

//TreeNode is of form ->
struct TreeNode{
  int val;
  struct TreeNode *left, *right;
}

void preorder(TreeNode *head,vector<int> &ans){
  if(root == NULL) return;
  ans.emplace_back(root->val);
  preorder(root->left);
  preorder(root->right);
}

//Return a array after preorder traversal
vector<int> preorderTraversal(TreeNode *root){
  vector<int> ans;
  preorder(root,ans);
  return ans; // Preorder traversal is stored in this vector
}
