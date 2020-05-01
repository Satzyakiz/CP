
// Using 1 stack

//Return a array after preorder traversal

vector<int> preorder(TreeNode *root){
  vector<int> ans;
  stack<TreeNode *> s;
  TreeNode * curr = root;
  while( curr || !s.empty()){
    ans.emplace_back(curr->val);
    if(curr->right) s.push(curr->right);
    if(curr->left) s.push(curr->left);
    if(!s.empty()){
      curr = s.top();
      s.pop();
    }
    else
      break;
  }
  return ans;
}
