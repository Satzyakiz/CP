// Given a binary tree containing N+1 with N edges nodes and an integer X.
// Your task is to complete the function countSubtreesWithSumX() that
// returns the count of the number of subtress having total node’s data
// sum equal to a value X.
// Example: For the tree given below:
//
//               5
//             /    \
//         -10     3
//         /    \    /  \
//       9     8  -4 7
//
// Subtree with sum 7:
//              -10
//             /      \
//           9        8
//
// and one node 7.
// Input:
// 2
// 5 -10 3 9 8 -4 7
// 7
// 1 2 3
// 5
// Output:
// 2
// 0
int check(Node *root,int x,int &ans){
    if(root == NULL)
        return 0;
    int l = check(root->left,x,ans);
    int r = check(root->right,x,ans);
    if(root->data + l + r == x)
        ans += 1;
    return l+r+root->data;
}
int countSubtreesWithSumX(Node* root, int x)
{
	// Code here
	int ans = 0;
	check(root,x,ans);
	return ans;
}
