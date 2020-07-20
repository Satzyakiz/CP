// Given below is a binary tree. The task is to print the top view
// of binary tree. Top view of a binary tree is the set of nodes visible
// when the tree is viewed from the top. For the given below tree
//
//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6      7
//
// Top view will be: 4 2 1 3 7
// Note: Print from leftmost node to rightmost node.


void topView(struct Node *root)
{
    //Your code here
    if(!root) return;
    queue<pair<struct Node*,int>> q;
    q.push({root,0});
    map<int,int> um;
    while(!q.empty()){
        pair<struct Node *, int> p = q.front();
        q.pop();
        if(um.find(p.second) == um.end()){
            um[p.second] = p.first->data;
        }
        if(p.first->left){
            q.push({p.first->left,p.second-1});
        }
        if(p.first->right){
            q.push({p.first->right,p.second+1});
        }
    }
    for(auto itr = um.begin(); itr != um.end(); itr++)
        cout<<itr->second<<" ";
}
