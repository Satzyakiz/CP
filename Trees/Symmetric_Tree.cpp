// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
// But the following [1,2,2,null,3,null,3] is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3

bool isSymmetric(TreeNode *root){
  if(root == NULL) return true;
  stack<TreeNode *> left,right;
  left.push(root);
  right.push(root);
  while(!left.empty()){
            TreeNode *leftNode, *rightNode;
            leftNode = left.top();
            rightNode = right.top();
            left.pop();
            right.pop();
            if(!leftNode && !rightNode)
                continue;
            if((!leftNode && rightNode )||(leftNode && !rightNode))
                return false;
            if(leftNode->val != rightNode->val)
                return false;
            left.push(leftNode->left);
            left.push(leftNode->right);
            right.push(rightNode->right);
            right.push(rightNode->left);
//The left child of left subtree needs to be equal
// to right child of right subtree
//The right child of left subtree needs to be equal
// to left child of right subtree
        }
        return true;
}

//Recursive Approach
int isSameTree(TreeNode* A, TreeNode* B){
  if(!A&&!B) return 1;
  if(!A||!B) return 0;
  if(A->val!=B->val) return 0;
  return isSameTree(A->left,B->right) && isSameTree(A->right,B->left);
}
int isSymmetric(TreeNode* A) {
  return isSameTree(A,A);
}
