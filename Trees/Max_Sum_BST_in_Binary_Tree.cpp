// Given a binary tree root, the task is to return the maximum sum 
// of all keys of any sub-tree which is also a Binary Search Tree (BST).
//
// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in
// root node with key equal to 3.


int ans;
int maxSumBST(TreeNode* root) {
    ans = 0;
    DFS(root);
    return ans;
}
vector<int> DFS(TreeNode *root){
    if(!root)
        return {1,0,INT_MAX,INT_MIN};
    auto left = DFS(root->left), right = DFS(root->right);

    if(left[0] && right[0] && root->val > left[3] && root->val < right[2]){
        int temp = left[1] + right[1] + root->val;
        ans = max(ans,temp);
        return {1, temp, min(left[2], root->val), max(right[3], root->val)};
    }

    return {0,0,0,0};
}
