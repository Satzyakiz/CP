// Given a binary tree, write a function to get the maximum width of the given
// tree. The width of a tree is the maximum width among all levels. The binary
// tree has the same structure as a full binary tree, but some nodes are null.
//
// The width of one level is defined as the length between the end-nodes
// (the leftmost and right most non-null nodes in the level, where the null
// nodes between the end-nodes are also counted into the length calculation.
//
// Example 1:
//
// Input:
//
//            1
//          /   \
//         3     2
//        / \     \
//       5   3     9
//
// Output: 4
// Explanation: The maximum width existing in the third level with the
// length 4 (5,3,null,9).
// Example 2:
//
// Input:
//
//           1
//          /
//         3
//        / \
//       5   3
//
// Output: 2
// Explanation: The maximum width existing in the third level with the
// length 2 (5,3).
// Example 3:
//
// Input:
//
//           1
//          / \
//         3   2
//        /
//       5
//
// Output: 2
// Explanation: The maximum width existing in the second level with the
// length 2 (3,2).
// Example 4:
//
// Input:
//
//           1
//          / \
//         3   2
//        /     \
//       5       9
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the
// length 8 (6,null,null,null,null,null,null,7).

int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    queue<pair<TreeNode *,long long>> q;
    q.push({root,1});
    long long ans = 0;
    while(!q.empty()){
        long long start = q.front().second, end = q.front().second;
        int k = q.size();
        while(k--){
            TreeNode *temp = q.front().first;
            end = q.front().second;
            q.pop();
            if(temp->left)
                q.push({temp->left,(2*end)%INT_MAX});
            if(temp->right)
                q.push({temp->right,(2*end+1)%INT_MAX});
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}
