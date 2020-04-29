// Using 1 stack

//Return a array after postorder traversal

vector<int> postorder(TreeNode *root){
  vector<int> ans;
  stack<TreeNode *> s;
  TreeNode *curr = root;
  while(curr || !s.empty()){
    //Input the element twice in the stack
    //It would help us to check whether the right part
    //is traversed or not
    while(curr){
      s.push(curr);
      s.push(curr);
      curr = curr ->left;
    }
    //If there are 2 copies present in the stack, it means right tree is not visited.
    curr = s.top();
    s.pop();
    if( !s.empty() && curr == s.top()){
      curr = curr->right;
    }
    else{
      ans.emplace_back(curr->val);
      //NULL needs to be set as otherwise the value would be the previous value and there would
      //be an infinite loop
      curr = NULL;
    }
  }
  return ans;
}
