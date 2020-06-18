// Given a binary search tree (BST) with duplicates, find all the mode(s)
// (the most frequently occurred element) in the given BST.
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than
// or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater
// than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

// For example:
// Given BST [1,null,2,2],
//
//    1
//     \
//      2
//     /
//    2
//
//
// return [2].
//
// Note: If a tree has more than one mode, you can return them in any order.
//Constant Space solution

vector<int> ans;
  TreeNode *prev;
  int currCount,maxCount;
  void inorder(TreeNode *root){
      if(root == NULL)
          return;
      inorder(root->left);
      if(prev != NULL && prev->val == root->val){
          currCount++;
      }else{
          currCount = 1;
      }
      if(currCount == maxCount){
          ans.emplace_back(root->val);
      }else if(currCount > maxCount){
          maxCount = currCount;
          ans = vector<int>();
          ans.emplace_back(root->val);
      }
      prev = root;
      inorder(root->right);
  }
  vector<int> findMode(TreeNode* root) {
      prev = NULL;
      currCount = 0,maxCount = 0;
      inorder(root);
      return ans;
  }
