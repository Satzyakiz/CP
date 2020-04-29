

// Using 1 stack

//Return a array after inorder traversal

vector<int> inorder(TreeNode *root){
  vector<int> ans;
  TreeNode *curr = root;
  stack<TreeNode *> s;
  while(curr || !s.empty()){
    while(curr){
      s.push(curr);
      curr= curr->left;
    }
    curr = s.top();
    s.pop();
    ans.emplace_back(curr->val);
    curr = curr->right;
  }
  return ans;
}
