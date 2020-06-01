
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
void flatten(TreeNode *root){
  if(!root) return;
  stack<TreeNode *> s;
  s.push(root);
  TreeNode *curr = NULL;
  while(!s.empty()){
    TreeNode *temp = s.top();
    s.pop();
    if(temp->right)
      s.push(temp->right);
    if(temp->left)
      s.push(temp->left);
    if(curr)
      curr->right = temp;
    curr = temp;
    curr->left = NULL;

  }
}
