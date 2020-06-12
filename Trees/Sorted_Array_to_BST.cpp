// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the
// following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5.

TreeNode *helper(vector<int> &nums,int l,int h){
        if(l > h)
            return NULL;
        int mid = l + (h-l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums,l,mid-1);
        root->right = helper(nums,mid+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root;
        root = helper(nums,0,nums.size()-1);
        return root;
    }
