// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

TreeNode *helper(vector<int> &preorder, int pStart,vector<int> &inorder, int iStart,int iEnd){
    if(iStart > iEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[pStart]);
    int index;
    for(int i=iStart; i<=iEnd; i++)
        if(inorder[i] == root->val){
            index = i;
            break;
        }
    root->left = helper(preorder,pStart+1,inorder,iStart,index-1);
    root->right = helper(preorder,pStart - iStart + index + 1 ,inorder,index+1,iEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder,0,inorder,0,inorder.size()-1);
}
