//     1
//     / \
//     2   3
//     /  \  \
//     4    6  5
//     /      \  \
//     7        9  8
//     /         \
//     10         12
// Input : Given above tree with parent pointer and node 10
// Output : 12
//
// Input:
// 2
// 10
// 1 2 L 1 3 R 2 4 L 2 6 R 4 7 L 7 10 L 6 9 R 9 12 R 3 5 R 5 8 R
// 7
// 2
// 1 2 L 1 3 R
// 2
// Output:
// 9
// 3

Node * getParent(Node *node){
    Node *curr = node;
    while(curr->parent != NULL)
        curr = curr->parent;
    return curr;
}
Node* findRightSibling(Node* node)
{
    // Code here
    Node *root = getParent(node);
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        int count = 0, k = q.size();
        while(count < k){
            Node *temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            if(temp == node && count == k-1)
                return NULL;
            else if(temp == node){
                return q.front();
            }
            count++;
        }
    }
    return NULL;
}
