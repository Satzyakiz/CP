// You are given a binary tree in which each node contains an integer value.
//
// Find the number of paths that sum to a given value.
//
// The path does not need to start or end at the root or a leaf, but
// it must go downwards (traveling only from parent nodes to child nodes).
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
//
// Return 3. The paths that sum to 8 are:
//
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

int checkSum(TreeNode *root,int sum){
        if(root == NULL) return 0;
        int left = checkSum(root->left,sum - root->val);
        int right = checkSum(root->right,sum - root->val);
        if(root->val == sum)
            return 1+left+right;
        else
            return left+right;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        return checkSum(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
