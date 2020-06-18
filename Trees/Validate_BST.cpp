// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//Doing Inorder traversal and checking if previous node is less than current node.
bool isValidBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *prev = NULL, *curr = root;
        while(curr != NULL || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if(prev != NULL && prev->val >= curr->val)
                return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
