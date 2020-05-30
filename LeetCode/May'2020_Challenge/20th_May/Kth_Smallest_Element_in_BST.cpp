// Given a binary search tree, write a function kthSmallest to
// find the kth smallest element in it.
//
//
//
// Example 1:
//
// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// Example 2:
//
// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3

int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderArr;
        TreeNode *curr = root;
        stack<TreeNode *> s;
        while(curr != NULL || !s.empty()){
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            inorderArr.emplace_back(curr->val);
            curr = curr->right;

        }
        return inorderArr[k-1];
    }
