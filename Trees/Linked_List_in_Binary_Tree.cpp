// Given a binary tree root and a linked list with head as the first node. 
//
// Return True if all the elements in the linked list starting from the head
// correspond to some downward path connected in the binary tree
// otherwise return False.
//
// In this context downward path means a path that starts at some node
// and goes downwards.

// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,
//                                 null,null,null,null,1,3]
// Output: true
// Explanation: Nodes in blue form a subpath in the binary Tree.

bool dfs(ListNode *head, TreeNode *root){
    if(!head)
        return true;
    if(!root)
        return false;
    if(root->val != head->val)
        return false;
    return dfs(head->next,root->left) || dfs(head->next,root->right);
}
bool isSubPath(ListNode* head, TreeNode* root) {
    if(!head)
        return true;
    if(!root)
        return false;

    return dfs(head,root) || isSubPath(head,root->left) ||isSubPath(head,root->right);
}
