//           1
//         /   \
//       0       1
//      / \     /  \
//     0   1   0    1
// ans:
//     4 + 5 + 6 + 7 = 22

// Example how a value is computed:
// (i) 7 : 111 => 1st: (0*2+1) , 2nd: (1*2+1) , 3rd: (3*2+1) = 7
// (ii) 6: 110 => 1st:  (0*2+1) , 2nd: (1*2+1), 3rd: (3*2+0) = 6

int ans = 0;
void sum(TreeNode *root,int tempSum){
  if(root == NULL) return;
  tempSum = tempSum * 2 + root->val;
  if(!root->left && !root->right)
    ans += tempSum;
  sum(root->left,tempSum);
  sum(root->right,tempSum);
}

int rootToLeaf(TreeNode *root){
  sum(root,0);
  return ans;
}
