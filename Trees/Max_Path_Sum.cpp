// Example 1:
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
// Example 2:
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42

int maxPathSum(TreeNode *root,int &res){
  if(root == NULL) return 0;
  int l = max(maxPathSum(root->left,res),0); // Ignore -ve sums
  int r = max(maxPathSum(root->right,res),0);
  int temp = max(l,r)+root->val;
  int ans = max(temp,l+r+root->val);
  res = max(res,ans);
  return temp;
}
