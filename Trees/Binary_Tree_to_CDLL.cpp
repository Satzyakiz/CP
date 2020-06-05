
// Given a Binary Tree of N edges. The task is to convert this to 
// a Circular Doubly Linked List(CDLL) in-place. The left and right
// pointers in nodes are to be used as previous and next pointers
// respectively in converted CDLL. The order of nodes in CDLL must
// be same as Inorder of the given Binary Tree. The first node of
// Inorder traversal (left most node in BT) must be head node of
// the CDLL.


void traverse(Node *root,Node **head_ref){
    if(root == NULL)
        return;
    traverse(root->right,head_ref);
    if(*head_ref)
        (*head_ref)->left = root;
    root->right = (*head_ref);
    *head_ref = root;
    traverse(root->left,head_ref);
}
Node *bTreeToCList(Node *root)
{
//add code here.
    Node *head_ref = NULL;
    traverse(root,&head_ref);
    Node *end = head_ref;
    while(end->right)
        end = end->right;

    head_ref->left = end;
    end->right = head_ref;

    return head_ref;

}
