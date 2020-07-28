// Given a rooted binary tree, return the lowest common ancestor of
// its deepest leaves.
//
// Recall that:
//
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0, and if the depth of a node is d,
// the depth of each of its children is d+1.
// The lowest common ancestor of a set S of nodes is the node A with the
// largest depth such that every node in S is in the subtree with root A.
//
//
// Example 1:
//
// Input: root = [1,2,3]
// Output: [1,2,3]
// Explanation:
// The deepest leaves are the nodes with values 2 and 3.
// The lowest common ancestor of these leaves is the node with value 1.
// The answer returned is a TreeNode object (not an array) with
// serialization "[1,2,3]".
// Example 2:
//
// Input: root = [1,2,3,4]
// Output: [4]
// Example 3:
//
// Input: root = [1,2,3,4,5]
// Output: [2,4,5]

TreeNode *lca;
int deepest;
int helper(TreeNode *root, int depth){
    deepest = max(deepest,depth);
    if(!root)
        return depth;
    int left = helper(root->left,depth+1);
    int right = helper(root->right,depth+1);
    if(left == deepest && right == deepest)
        lca = root;
    return max(left,right);
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    deepest = 0;
    helper(root,0);
    return lca;
}
