// Given a Binary Tree. Check whether all of its nodes have the value equal
// to the sum of their child nodes.
//
// Example 1:
//
// Input:
//      10
//     /
//   10
// Output: 1
// Explanation: Here, every node is sum of
// its left and right child.
// Example 2:
//
// Input:
//        1
//      /   \
//     4     3
//    /  \
//   5    N
// Output: 0
// Explanation: Here, 1 is the root node
// and 4, 3 are its child nodes. 4 + 3 =
// 7 which is not equal to the value of
// root node. Hence, this tree does not
// satisfy the given conditions.

int isSumProperty(Node *root)
{
 // Add your code here
    if(!root) return 1;
    if(!root->left && !root->right)
        return 1;
    int left = root->left ? root->left->data : 0;
    int right = root->right ? root->right->data : 0;
    if(root->data != left + right)
        return 0;
    return isSumProperty(root->left) && isSumProperty(root->right);
}
