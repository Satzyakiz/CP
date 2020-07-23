// Given A binary Tree. Your task is to remove all the half nodes
// (which has only one child).

Node *RemoveHalfNodes(Node *root)
{
   //add code here.
   if(!root)
    return NULL;
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if(!root->left && root->right)
        return root->right;
    if(root->left && !root->right)
        return root->left;
    return root;

}

//Another Solution
void helper(TreeNode *A){
    if(!A)
        return;
    if(!A->left && A->right){
        A->val = A->right->val;
        A->left = A->right->left;
        A->right = A->right->right;
        helper(A);
    }
    else if(A->left!=NULL && A->right==NULL ){
        A->val = A->left->val;
        A->right = A->left->right;
        A->left = A->left->left;
        helper(A);
    }
    else if(A->left!=NULL && A->right!=NULL ){
        helper(A->left);
        helper(A->right);
    }
}
TreeNode* Solution::solve(TreeNode* A) {
    helper(A);
    return A;
}
