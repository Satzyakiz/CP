
// Input: 
// 	Tree 1                     Tree 2
//           1                         2
//          / \                       / \
//         3   2                     1   3
//        /                           \   \
//       5                             4   7
// Output:
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \
// 	 5   4   7
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2){
  if(!t1) return t2;
  if(!t2) return t1;
  t1->val += t2->val;
  t1->left = mergeTrees(t1->left,t2->left);
  t1->right = mergeTrees(t1->right,t2->right);
  return t1;
}
