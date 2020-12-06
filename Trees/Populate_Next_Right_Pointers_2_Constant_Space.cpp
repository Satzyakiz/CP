// Populating Next Right Pointers in Each Node II
//
// Solution
// Given a binary tree
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.

// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]

void helper(Node *root){
    if(!root) return;
    Node *dummy = new Node(INT_MIN, NULL, NULL, NULL), *curr, *prev;
    for(curr = root, prev = dummy; curr; curr = curr->next){
        if(curr->left){
            prev->next = curr->left;
            prev = prev->next;
        }
        if(curr->right){
            prev->next = curr->right;
            prev = prev->next;
        }
    }
    connect(dummy->next);
    delete dummy;
}
Node* connect(Node* root) {
    helper(root);
    return root;
}
