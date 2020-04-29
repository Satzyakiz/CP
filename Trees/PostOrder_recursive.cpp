

//TreeNode is of form ->
struct TreeNode{
  int val;
  struct TreeNode *left, *right;
}

void postorder(TreeNode *head,vector<int> &ans){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  ans.emplace_back(root->val);
}

//Return a array after postorder traversal
vector<int> postorderTraversal(TreeNode *root){
  vector<int> ans;
  postorder(root,ans);
  return ans; // Postorder traversal is stored in this vector
}
