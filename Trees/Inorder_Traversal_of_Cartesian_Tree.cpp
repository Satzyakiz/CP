

// Given an inorder traversal of a cartesian tree, construct the tree.
//
//  Cartesian tree : is a heap ordered binary tree, where the root is
//  greater than all the elements in the subtree.
//  Note: You may assume that duplicates do not exist in the tree.
// Example :
//
// Input : [1 2 3]
//
// Return :
//           3
//          /
//         2
//        /
//       1


TreeNode* Solution::buildTree(vector<int> &A) {
    if(A.empty()) return NULL;
    auto maxIndex = max_element(A.begin(),A.end());
    TreeNode *root = new TreeNode(*maxIndex);
    vector<int> leftSubtree(A.begin(),maxIndex);
    vector<int> rightSubtree(maxIndex+1,A.end());
    root->left = buildTree(leftSubtree);
    root->right = buildTree(rightSubtree);
    return root;
}
