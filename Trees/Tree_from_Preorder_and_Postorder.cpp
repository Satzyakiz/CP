// Return any binary tree that matches the given preorder and postorder traversals.
//
// Values in the traversals pre and post are distinct positive integers.
//
//
//
// Example 1:
//
// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]

int preIndex = 0, postIndex = 0;
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    TreeNode *root = new TreeNode(pre[preIndex]);
    preIndex++;
    if(root->val != post[postIndex]){
        root->left = constructFromPrePost(pre,post);
    }
    if(root->val != post[postIndex]){
        root->right = constructFromPrePost(pre,post);
    }
    postIndex++;
    return root;
}
