// Given a binary tree, you need to compute the length of
// the diameter of the tree. The diameter of a binary tree is
// the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
//
// Example:
// Given a binary tree
//           1
//          / \
//         2   3
//        / \
//       4   5
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

int diameter(TreeNode *root,int &res){
    if(root == NULL) return 0;
    int l = diameter(root->left,res);
    int r = diameter(root->right,res);


    int temp = max(l,r)+1;
    int ans = max(temp,l+r+1);
    res = max(res,ans);

    return temp;
}
int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int res = INT_MIN;
        diameter(root,res);
        return res-1; //Important
    }
