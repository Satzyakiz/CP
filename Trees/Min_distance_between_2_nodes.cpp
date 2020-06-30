// Given a binary tree and two node values your task is to find 
// the minimum distance between them.


Node *LCA(Node *root,int a, int b){
    if(root == NULL)
        return NULL;
    if(root->data == a || root->data == b)
        return root;
    Node *left = LCA(root->left,a,b);
    Node *right = LCA(root->right,a,b);
    if(left && right)
        return root;
    return left == NULL ? right : left;
}

int dist(Node *root,int data,int d){

    if(root == NULL)
        return -1;
    if(root->data == data){
        return d;
    }
    int l=dist(root->left,data,d+1);
    int r=dist(root->right,data,d+1);
    return max(l,r);
}
int findDist(Node* root, int a, int b) {
    Node *lca = LCA(root,a,b);
    int s1 = 0,s2 = 0;

    s1 = dist(lca,a,0);

    s2 = dist(lca,b,0);
    // cout<<lca->data<<endl;
    // cout<<s1<<" "<<s2<<endl;
    return s1+s2;
}
