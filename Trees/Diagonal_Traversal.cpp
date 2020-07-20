
// Consider lines of slope -1 passing between nodes.
//
// Given a Binary Tree A containing N nodes, return all diagonal elements
// in a binary tree belonging to same line.
//
// Input 1:
//
//             1
//           /   \
//          4      2
//         / \      \
//        8   5      3
//           / \    /
//          9   7  6
// Input 2:
//
//              11
//           /     \
//          20      12
//         / \       \
//        1   15      13
//           /  \     /
//          2    17  16
//           \   /
//           22 34
//
//
// Example Output
// Output 1:
//
//  [1, 2, 3, 4, 5, 7, 6, 8, 9]
// Output 2:
//
//  [11, 12, 13, 20, 15, 17, 16, 1, 2, 22, 34]


vector<int> Solution::solve(TreeNode* A) {
    vector<int> v;
    queue<TreeNode *> q;
    q.push(A);
    while(!q.empty()){
        TreeNode * x = q.front();
        q.pop();
        v.push_back(x->val);
        if(x->left!=NULL){
            q.push(x->left);
        }
        x=x->right;
        while(x!=NULL){
            v.push_back(x->val);
            if(x->left!=NULL){
                q.push(x->left);
            }
             x=x->right;
        }
    }
    return v;
}
