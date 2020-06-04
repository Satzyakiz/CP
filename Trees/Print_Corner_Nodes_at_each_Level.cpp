//Source: GFG
// Given a Binary Tree, Print the corner nodes at each level.
// The node at the leftmost and the node at the rightmost of each level.

void printCorner(Node *root)
{
    if(root==NULL) return ;

    queue<Node*> q;
    q.push(root);
    int p=0;
    while(!q.empty()) {
        p = q.size();
        for(int i=1;i<=p;i++) {
            root = q.front();
            q.pop();
            if(i==1 || i==p) {
                cout<<root->data<<" ";
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
}
