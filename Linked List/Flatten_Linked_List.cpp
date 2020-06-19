// Given a Linked List of size N, where every node represents a linked list
// and contains two pointers of its type:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
//
// You have to flatten the linked list to a single linked list which
// should be sorted.
// Note: The flattened list will be printed using the bottom pointer
// instead of next pointer.

//Constant Space Solution
Node * merge(Node * first, Node * second)
{
    if(first==NULL)
    return second;

    if(second==NULL)
    return first;

    Node * final;
    if(first->data<second->data)
    {
        final=first;
        final->bottom=merge(first->bottom, second);

    }

    else
    {
        final=second;
        final->bottom=merge(first, second->bottom);
    }

    final->next=NULL;
    return final;
}
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    return root;

    return merge(root,flatten(root->next));

}
