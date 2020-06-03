
// Given a Binary Tree, the task is to extract all leaves of it 
// in a Doubly Linked List (DLL). Note that the DLL needs to be
// created in-place. Assume that the node structure of DLL and
// Binary Tree is the same, only the meaning of left and right
// pointers are different. In DLL, left means previous pointer
// and right means next pointer. Head of DLL should point to the
// leftmost leaf and then in inorder traversal and so on.







Node *convertToDLL(Node *root, Node **head_ref) {
    // add code here.
    if(root == NULL) return NULL;
    if(!root->left && !root->right){
        root->right = *head_ref;
        if(*head_ref != NULL)
            (*head_ref)->left = root;
        *head_ref = root;
        return NULL;
    }
    root->right = convertToDLL(root->right,head_ref);
    root->left = convertToDLL(root->left,head_ref);
    return root;
}
